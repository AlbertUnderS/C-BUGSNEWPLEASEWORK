#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <list>
#include <fstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

class Board {
private:
    std::vector<Bug*> bugs;  // Vector of pointers to all bugs (polymorphic)
    std::vector<std::vector<std::list<Bug*>>> grid; // 10x10 grid of bugs

public:
    Board() : grid(10, std::vector<std::list<Bug*>>(10)) {}
    ~Board() {
        for (auto bug : bugs)
            delete bug;
    }

    void initializeFromFile(const std::string& filename);

    void updateBoard();
    void tapBoard();

    void displayAllBugs() const;
    void displayAllCells() const;
    void displayLifeHistories() const;

    void findBugById(int id) const;

    void writeLifeHistoryToFile(std::ofstream& outFile) const;

    void runSimulation();

private:
    void resolveFightsInCell(int x, int y);
};

#endif // BOARD_H
