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

    // Helper function for displaying coordinates
    std::string toString() const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};

#endif // POSITION_H
