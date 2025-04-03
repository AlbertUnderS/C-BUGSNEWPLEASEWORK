//
// Created by arago on 31/03/2025.
//
#include "Crawler.h"
#include <cstdlib>  // For random number generation

Crawler::Crawler(int id, int x, int y, Direction direction, int size)
    : id(id), position({x, y}), direction(direction), size(size), alive(true) {
}

bool Crawler::isWayBlocked() {
    switch (direction) {
        case Direction::North:
            return position.y == 0;
        case Direction::East:
            return position.x == 9;  // Assuming a 10x10 grid (0-9)
        case Direction::South:
            return position.y == 9;
        case Direction::West:
            return position.x == 0;
        default:
            return false;
    }
}

void Crawler::move() {
    if (isWayBlocked()) {
        // Pick a new random direction if movement is blocked
        direction = static_cast<Direction>(rand() % 4 + 1);
    }

    // Move in the current direction
    switch (direction) {
        case Direction::North:
            position.y--;
        break;
        case Direction::East:
            position.x++;
        break;
        case Direction::South:
            position.y++;
        break;
        case Direction::West:
            position.x--;
        break;
    }

    // Save new position to movement history
    addPath(position);
}

void Crawler::setDirection(Direction newDirection) {
    direction = newDirection;
}

void Crawler::display() const {
    std::string dirStr;
    switch (direction) {
        case Direction::North: dirStr = "North"; break;
        case Direction::East: dirStr = "East"; break;
        case Direction::South: dirStr = "South"; break;
        case Direction::West: dirStr = "West"; break;
    }

    std::cout << id << " Crawler (" << position.x << "," << position.y << ") "
              << size << " " << dirStr << " " << (alive ? "Alive" : "Dead") << std::endl;
}
