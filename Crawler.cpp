//
// Created by arago on 31/03/2025.
//

#include "Crawler.h"
#include <cstdlib>  // for rand()
#include <ctime>

// Constructor
Crawler::Crawler(int id, int x, int y, Direction dir, int size)
    : id(id), position(x, y), direction(dir), size(size), alive(true) {
    path.push_back(position); // Start position is recorded
}

// Move function
void Crawler::move() {
    if (alive) {
        // Check if blocked and change direction if necessary
        while (isWayBlocked()) {
            direction = static_cast<Direction>((rand() % 4) + 1);
        }

        // Move the bug one step in its current direction
        switch (direction) {
            case Direction::North: position.y--; break;
            case Direction::East:  position.x++; break;
            case Direction::South: position.y++; break;
            case Direction::West:  position.x--; break;
        }

        // Record new position
        path.push_back(position);
    }
}

// Check if the bug is at the edge of the board
bool Crawler::isWayBlocked() const {
    return (direction == Direction::North && position.y == 0) ||
           (direction == Direction::East && position.x == 9) ||
           (direction == Direction::South && position.y == 9) ||
           (direction == Direction::West && position.x == 0);
}

// Display bug details
void Crawler::display() const {
    std::cout << id << " Crawler " << position.toString()
              << " " << size << " "
              << (alive ? "Alive" : "Dead") << std::endl;
}
