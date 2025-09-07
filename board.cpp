#include "Board.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <thread>
#include <chrono>

// Initialize from file
void Board::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;

        std::getline(ss, token, ';');
        char type = token[0];

        int id, x, y, dirInt, size;
        std::getline(ss, token, ';'); id = std::stoi(token);
        std::getline(ss, token, ';'); x = std::stoi(token);
        std::getline(ss, token, ';'); y = std::stoi(token);
        std::getline(ss, token, ';'); dirInt = std::stoi(token);
        std::getline(ss, token, ';'); size = std::stoi(token);
        Direction dir = static_cast<Direction>(dirInt);

        if (type == 'C') {
            bugs.push_back(new Crawler(id, x, y, dir, size));
        } else if (type == 'H') {
            std::getline(ss, token, ';');
            int hopLength = std::stoi(token);
            bugs.push_back(new Hopper(id, x, y, dir, size, hopLength));
        }
    }

    file.close();
    std::cout << "Loaded " << bugs.size() << " bugs from " << filename << std::endl;
    updateBoard();
}

void Board::updateBoard() {
    for (auto& row : grid)
        for (auto& cell : row)
            cell.clear();

    for (auto bug : bugs) {
        if (!bug->isAlive()) continue;
        Position pos = bug->getPosition();
        grid[pos.y][pos.x].push_back(bug);
    }
}

void Board::displayAllBugs() const {
    for (auto bug : bugs)
        if (bug->isAlive())
            bug->display();
}

void Board::findBugById(int id) const {
    for (auto bug : bugs) {
        if (bug->getId() == id) {
            bug->display();
            return;
        }
    }
    std::cout << "Bug " << id << " not found.\n";
}

void Board::tapBoard() {
    for (auto bug : bugs)
        bug->move();

    updateBoard();

    for (int y = 0; y < 10; ++y)
        for (int x = 0; x < 10; ++x)
            resolveFightsInCell(x, y);
}

void Board::displayLifeHistories() const {
    for (auto bug : bugs)
        bug->displayLifeHistory();
}

void Board::displayAllCells() const {
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            std::cout << "(" << x << "," << y << "): ";
            if (grid[y][x].empty())
                std::cout << "empty\n";
            else {
                for (auto bug : grid[y][x])
                    std::cout << (bug->isAlive() ? "" : "[Dead]") << bug->getId() << " ";
                std::cout << "\n";
            }
        }
    }
}

void Board::writeLifeHistoryToFile(std::ofstream& out) const {
    for (auto bug : bugs)
        bug->writeLifeHistory(out);
}

void Board::resolveFightsInCell(int x, int y) {
    auto& cell = grid[y][x];
    if (cell.size() <= 1) return;

    cell.sort([](Bug* a, Bug* b) { return a->getSize() > b->getSize(); });

    Bug* winner = cell.front();
    int totalSize = winner->getSize();

    auto it = ++cell.begin();
    while (it != cell.end()) {
        Bug* loser = *it;
        if (loser->isAlive()) {
            loser->setAlive(false);
            totalSize += loser->getSize();
            loser->setEatenById(winner->getId());
        }
        ++it;
    }

    winner->setSize(totalSize);
}

void Board::runSimulation() {
    int round = 0;
    while (true) {
        int aliveCount = 0;
        for (auto bug : bugs)
            if (bug->isAlive()) aliveCount++;

        if (aliveCount <= 1) break;

        std::cout << "Round " << ++round << ":\n";

        tapBoard();
        displayAllBugs();

        std::ofstream outFile("simulation_round_" + std::to_string(round) + ".txt");
        if (outFile) writeLifeHistoryToFile(outFile);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Simulation complete. Last bug standing:\n";
    displayAllBugs();
}
