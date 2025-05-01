#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <string>
#include "Position.h"

enum class Direction { North = 1, East, South, West };

class Crawler {
private:
    int id;
    Position position;
    Direction direction;
    int size;
    bool alive;
    int eatenById;
    std::list<Position> path;

public:
    Crawler(int id, int x, int y, Direction direction, int size)
       : id(id), position({x, y}), direction(direction), size(size), alive(true), eatenById(-1) {}

    Crawler(int id, Position position) : id(id), position(position) {}

    // Basic getters
    int getId() const { return id; }
    Position getPosition() const { return position; }
    int getSize() const { return size; }
    void setSize(int newSize) { size = newSize; }

    const std::list<Position>& getPath() const { return path; }

    // Setters
    void setEatenById(int id) { eatenById = id; }
    int getEatenById() const { return eatenById; }

    // Core behaviors
    void move();
    bool isWayBlocked();
    void display() const;
    bool isAlive() const { return alive; }
    void addPath(Position newPos) { path.push_back(newPos); }

    // File output
    void writeLifeHistory(std::ostream& out) const {
        out << id << " Crawler Path: ";
        for (const auto& p : path) {
            out << p.toString() << ",";
        }
        if (eatenById != -1) {
            out << " Eaten by " << eatenById;
        }
        out <<std::endl;
    }
    void setAlive(bool status) {
        if (alive && !status) {
            std::cout << "Bug " << id << " is now dead at position " << position.toString() << std::endl;
        }
        alive = status;
    }

    void displayLifeHistory() const {
        std::cout << id << " Crawler Path: ";
        for (const auto& p : path) {
            std::cout << p.toString() << ",";
        }
        if (eatenById != -1) {
            std::cout << " Eaten by " << eatenById;
        }
        std::cout << std::endl;
    }

};

#endif // CRAWLER_H
