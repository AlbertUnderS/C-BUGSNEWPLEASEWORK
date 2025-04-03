//
// Created by arago on 31/03/2025.
//

#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // For random numbers

void Board::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error: Unable to open the file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char type;
        int id, x, y, dir, size;

        ss >> type;  // 'C' for crawler
        ss.ignore();  // Skip the comma
        ss >> id;
        ss.ignore();
        ss >> x;
        ss.ignore();
        ss >> y;
        ss.ignore();
        ss >> dir;
        ss.ignore();
        ss >> size;

        Direction direction = static_cast<Direction>(dir);  // Convert integer to Direction enum

        // Dynamically allocate Crawler and add to the vector
        Crawler* newCrawler = new Crawler(id, x, y, direction, size);
        crawlers.push_back(newCrawler);
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
            std::cout << crawler->getId() << " Crawler ("
                      << crawler->getPosition().x << ","
                      << crawler->getPosition().y << ") "
                      << crawler->getSize() << " ";

            // Convert direction to readable string
            switch (crawler->getDirection()) {
                case Direction::North: std::cout << "North "; break;
                case Direction::East: std::cout << "East "; break;
                case Direction::South: std::cout << "South "; break;
                case Direction::West: std::cout << "West "; break;
                default: std::cout << "Unknown "; break;
            }

            std::cout << (crawler->isAlive() ? "Alive" : "Dead") << std::endl;
        }
    }
}
