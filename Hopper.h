#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"
#include <cstdlib>
#include <string>
#include "Crawler.h"  // for Direction enum

class Hopper : public Bug {
private:
    Direction direction;
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction dir, int size, int hopLen)
        : Bug(id, Position(x, y), size), direction(dir), hopLength(hopLen) {}

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
            case Direction::North: position.y = std::max(0, position.y - hopLength); break;
            case Direction::East:  position.x = std::min(9, position.x + hopLength); break;
            case Direction::South: position.y = std::min(9, position.y + hopLength); break;
            case Direction::West:  position.x = std::max(0, position.x - hopLength); break;
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
        std::cout << id << " Hopper (" << position.x << "," << position.y << ") "
                  << size << " " << dirStr << " hop=" << hopLength
                  << " " << (alive?"Alive":"Dead") << std::endl;
    }

    void writeLifeHistory(std::ostream& out) const override {
        out << id << " Hopper Path: ";
        for (auto p : path) out << p.toString() << ",";
        if (eatenById != -1) out << " Eaten by " << eatenById;
        out << std::endl;
    }

    void displayLifeHistory() const override {
        std::cout << id << " Hopper Path: ";
        for (auto p : path) std::cout << p.toString() << ",";
        if (eatenById != -1) std::cout << " Eaten by " << eatenById;
        std::cout << std::endl;
    }
};

#endif // HOPPER_H
