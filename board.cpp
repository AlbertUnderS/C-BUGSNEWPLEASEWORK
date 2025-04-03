//
// Created by arago on 31/03/2025.
//
#include "Board.h"
#include <iostream>
#include <fstream>

Board::Board() {}

Board::~Board() {
    for (auto crawler : crawlers) {
        delete crawler;  // Clean up dynamically allocated crawlers
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

    for (auto& crawler : crawlers) {
        if (crawler->isAlive()) {
            crawler->move();
        }
    }

    std::cout << "New positions after tap:\n";
    displayAllBugs();
}
