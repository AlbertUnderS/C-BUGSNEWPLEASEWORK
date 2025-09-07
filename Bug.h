#ifndef BUG_H
#define BUG_H

#include "Position.h"
#include <list>
#include <iostream>

class Bug {
protected:
    int id;
    Position position;
    int size;
    bool alive;
    int eatenById;
    std::list<Position> path;

public:
    Bug(int id, Position pos, int size)
        : id(id), position(pos), size(size), alive(true), eatenById(-1) {}

    virtual ~Bug() = default;

    int getId() const { return id; }
    Position getPosition() const { return position; }
    int getSize() const { return size; }
    void setSize(int s) { size = s; }

    bool isAlive() const { return alive; }
    void setAlive(bool status) { alive = status; }

    void addPath(Position p) { path.push_back(p); }

    int getEatenById() const { return eatenById; }
    void setEatenById(int id) { eatenById = id; }

    const std::list<Position>& getPath() const { return path; }


    virtual void move() = 0;
    virtual void display() const = 0;


    virtual void writeLifeHistory(std::ostream& out) const = 0;
    virtual void displayLifeHistory() const = 0;
};

#endif
