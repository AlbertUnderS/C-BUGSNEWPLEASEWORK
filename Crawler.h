//
// Created by arago on 31/03/2025.
//
#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>

// Define Direction enum class for better readability
enum class Direction {
    North = 1,
    East,
    South,
    West
};

// Position structure for easier coordinate management
struct Position {
    int x, y;
};

class Crawler {
private:
    int id;
    Position position;
    Direction direction;
    int size;
    bool alive;
    std::list<Position> path;  // List to store the path of the crawler

public:
    Crawler(int id, int x, int y, Direction dir, int size);

    int getId() const { return id; }
    Position getPosition() const { return position; }
    Direction getDirection() const { return direction; }
    int getSize() const { return size; }
    bool isAlive() const { return alive; }

    // Method to display the crawler's status
    void display() const;

    // Method to update movement and other behavior
    void move();
};

#endif
