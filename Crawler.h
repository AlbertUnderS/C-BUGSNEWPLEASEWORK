//
// Created by arago on 31/03/2025.
//
#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <vector>
#include "Position.h"  // ✅ Make sure this is included!

enum class Direction { North = 1, East, South, West };

class Crawler {
private:
    int id;
    Position position;  // ✅ Now Position is recognized!
    Direction direction;
    int size;
    bool alive;
    std::list<Position> path;

public:
    // Constructor
    Crawler(int id, int x, int y, Direction dir, int size);

    // Movement logic
    void move();

    // Check if movement is blocked
    bool isWayBlocked() const;

    // Display bug details
    void display() const;

    // Getters
    int getId() const { return id; }
    Position getPosition() const { return position; }
    bool isAlive() const { return alive; }
};

#endif // CRAWLER_H
