//
// Created by arago on 31/03/2025.
//
#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>  // For tracking the path history

enum class Direction { North = 1, East, South, West };

struct Position {
    int x;
    int y;
};

class Crawler {
private:
    int id;
    Position position;
    Direction direction;
    int size;
    bool alive;
    std::list<Position> path;

public:
    Crawler(int id, int x, int y, Direction direction, int size);
    void move();  // Move the bug
    bool isWayBlocked();  // Check if movement is blocked
    void display() const;  // Display the bug details
    bool isAlive() const { return alive; }  // Check if the bug is alive
    int getId() const { return id; }  // Get the bug ID
    void setDirection(Direction newDirection);  // Set a new direction
    Position getPosition() const { return position; }  // Get the bug position
    void addPath(Position newPos) { path.push_back(newPos); }  // Add to movement history
};

#endif
