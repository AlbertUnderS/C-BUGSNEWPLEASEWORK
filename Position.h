//
// Created by arago on 31/03/2025.
//
#ifndef POSITION_H
#define POSITION_H

#include <string>

struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // Equality operator for Position comparison
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    std::string toString() const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

};

#endif
