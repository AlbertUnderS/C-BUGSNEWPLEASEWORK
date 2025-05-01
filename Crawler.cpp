//
// Created by arago on 31/03/2025.
//

#include "Crawler.h"
#include <cstdlib>  // For rand()
#include <iostream>

bool Crawler::isWayBlocked() {
    switch (direction) {
        case Direction::North:
            return position.y == 0;
        case Direction::East:
            return position.x == 9;
        case Direction::South:
            return position.y == 9;
        case Direction::West:
            return position.x == 0;
        default:
            return false;
    }
}

void Crawler::move() {
    if (!alive) return;

    if (isWayBlocked()) {
        direction = static_cast<Direction>(rand() % 4 + 1);
    }

    switch (direction) {
        case Direction::North:
            if (position.y > 0) position.y--;
        break;
        case Direction::East:
            if (position.x < 9) position.x++;
        break;
        case Direction::South:
            if (position.y < 9) position.y++;
        break;
        case Direction::West:
            if (position.x > 0) position.x--;
        break;
    }

    addPath(position);
}

void Crawler::display() const {
    std::string dirStr;
    switch (direction) {
        case Direction::North: dirStr = "North"; break;
        case Direction::East:  dirStr = "East";  break;
        case Direction::South: dirStr = "South"; break;
        case Direction::West:  dirStr = "West";  break;
    }

    std::cout << id << " Crawler (" << position.x << "," << position.y << ") "
              << size << " " << dirStr << " " << (alive ? "Alive" : "Dead") << std::endl;
}


