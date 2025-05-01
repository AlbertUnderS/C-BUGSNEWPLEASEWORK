#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>

Board::Board() : grid(10, std::vector<std::list<Crawler*>>(10)) {}

Board::~Board() {
    for (auto crawler : crawlers) {
        delete crawler;
    }
}

void Board::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open the file!" << std::endl;
        return;
    }

    int id, x, y, size, dir;
    while (file >> id >> x >> y >> size >> dir) {
        Direction direction = static_cast<Direction>(dir);
        Crawler* crawler = new Crawler(id, x, y, direction, size);
        crawlers.push_back(crawler);
    }

    file.close();
}

void Board::displayAllBugs() const {
    if (crawlers.empty()) {
        std::cout << "No bugs on the board." << std::endl;
        return;
    }

    for (const auto& crawler : crawlers) {
        if (crawler->isAlive()) {
            crawler->display();
        }
    }
}

void Board::findBugById(int id) const {
    for (const auto& crawler : crawlers) {
        if (crawler->getId() == id) {
            crawler->display();
            return;
        }
    }
    std::cout << "Bug " << id << " not found." << std::endl;
}

void Board::tapBoard() {
    std::cout << "Tapping the board...\n";

    // Move all crawlers
    for (auto& crawler : crawlers) {
        if (crawler->isAlive()) {
            crawler->move();
        }
    }

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            resolveFightsInCell(x, y);
        }
    }

    int aliveCount = 0;
    for (const auto& crawler : crawlers) {
        if (crawler->isAlive()) {
            aliveCount++;
        }
    }

    std::cout << "New positions after tap:\n";
    displayAllBugs();

    if (aliveCount <= 1) {
        std::cout << "Game Over! Last bug standing!\n";
        exit(0);
    }
}

void Board::displayLifeHistories() const {
    std::cout << "Displaying life history of all bugs:\n";
    for (const auto& crawler : crawlers) {
        crawler->displayLifeHistory();
    }
}

// Board.cpp

void Board::writeLifeHistoryToFile(std::ofstream& outFile) const {
    outFile << "Life History of all Bugs:\n";
    for (const auto& crawler : crawlers) {
        outFile << crawler->getId() << " Crawler Path: ";
        const auto& path = crawler->getPath();
        for (const auto& pos : path) {
            outFile << pos.toString() << ",";
        }

        int eatenId = crawler->getEatenById();
        if (eatenId == -1) {
            outFile << " Not eaten.\n";
        } else {
            outFile << " Eaten by " << eatenId << "\n";
        }
    }
}


void Board::updateBoard() {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.clear();
        }
    }


    for (const auto& crawler : crawlers) {
        Position pos = crawler->getPosition();
        grid[pos.y][pos.x].push_back(crawler);
    }
}

void Board::displayAllCells() const {
    std::cout << "Displaying all cells:\n";
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            std::cout << "(" << x << "," << y << "): ";
            if (grid[y][x].empty()) {
                std::cout << "empty\n";
            } else {
                for (const auto& crawler : grid[y][x]) {
                    std::cout << "Crawler " << crawler->getId() << " ";
                }
                std::cout << "\n";
            }
        }
    }
}

void Board::resolveFightsInCell(int x, int y) {
    std::list<Crawler*>& cell = grid[y][x];

    if (cell.size() <= 1) return;

    cell.sort([](Crawler* a, Crawler* b) {
        return a->getSize() > b->getSize();
    });

    Crawler* winner = cell.front();
    int totalSize = winner->getSize();

    std::list<Crawler*>::iterator it = ++cell.begin();

    while (it != cell.end()) {
        Crawler* loser = *it;
        if (loser->isAlive()) {
            loser->setAlive(false);
            totalSize += loser->getSize();
        }
        ++it;
    }

    winner->setSize(totalSize);
}

void Board::runSimulation() {
    int round = 0;
    while (crawlers.size() > 1) {
        std::cout << "Round " << ++round << ":\n";
        tapBoard();

        displayAllBugs();

        std::ofstream outFile("simulation_round_" + std::to_string(round) + ".txt");
        if (outFile) {
            writeLifeHistoryToFile(outFile);
            std::cout << "Life history written to simulation_round_" << round << ".txt\n";
        } else {
            std::cerr << "Error: Could not write to file!\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));  // This makes the simulation pause for a second
    }


    std::cout << "Simulation complete. Last bug standing:\n";
    displayAllBugs();
}