//
// Created by arago on 31/03/2025.
//

#include "Crawler.h"
#include <iostream>
#include <cstdlib>  // For random numbers

Crawler::Crawler(int id, int x, int y, Direction dir, int size)
    : id(id), position{ x, y }, direction(dir), size(size), alive(true) {}

void Crawler::display() const {
    std::cout << id << " Crawler (" << position.x << "," << position.y << ") "
              << size << " ";

    // Convert direction to a string
    switch (direction) {
        case Direction::North: std::cout << "North "; break;
        case Direction::East: std::cout << "East "; break;
        case Direction::South: std::cout << "South "; break;
        case Direction::West: std::cout << "West "; break;
        default: std::cout << "Unknown "; break;
    }

    std::cout << (alive ? "Alive" : "Dead") << std::endl;
}

void Crawler::move() {
    // Implement movement logic here based on direction
    switch (direction) {
        case Direction::North: position.y -= 1; break;
        case Direction::East: position.x += 1; break;
        case Direction::South: position.y += 1; break;
        case Direction::West: position.x -= 1; break;
        default: break;
    }
    path.push_back(position);
}

