#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"
#include <cstdlib>
#include <string>

enum class Direction { North = 1, East, South, West };

class Crawler : public Bug {
private:
    Direction direction;

public:
    Crawler(int id, int x, int y, Direction dir, int size)
        : Bug(id, Position(x, y), size), direction(dir) {}

    bool isWayBlocked() const {
        switch (direction) {
            case Direction::North: return position.y == 0;
            case Direction::East:  return position.x == 9;
            case Direction::South: return position.y == 9;
            case Direction::West:  return position.x == 0;
        }
        return false;
    }

    void move() override {
        if (!alive) return;

        if (isWayBlocked()) {
            direction = static_cast<Direction>(rand() % 4 + 1);
        }

        switch (direction) {
            case Direction::North: if(position.y>0) position.y--; break;
            case Direction::East:  if(position.x<9) position.x++; break;
            case Direction::South: if(position.y<9) position.y++; break;
            case Direction::West:  if(position.x>0) position.x--; break;
        }

        addPath(position);
    }

    void display() const override {
        std::string dirStr;
        switch (direction) {
            case Direction::North: dirStr="North"; break;
            case Direction::East:  dirStr="East";  break;
            case Direction::South: dirStr="South"; break;
            case Direction::West:  dirStr="West";  break;
        }
        std::cout << id << " Crawler (" << position.x << "," << position.y << ") "
                  << size << " " << dirStr << " " << (alive?"Alive":"Dead") << std::endl;
    }

    void writeLifeHistory(std::ostream& out) const override {
        out << id << " Crawler Path: ";
        for (auto p : path) out << p.toString() << ",";
        if (eatenById != -1) out << " Eaten by " << eatenById;
        out << std::endl;
    }

    void displayLifeHistory() const override {
        std::cout << id << " Crawler Path: ";
        for (auto p : path) std::cout << p.toString() << ",";
        if (eatenById != -1) std::cout << " Eaten by " << eatenById;
        std::cout << std::endl;
    }
};

#endif // CRAWLER_H
