//
// Created by arago on 31/03/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <list>
#include <fstream>
#include "Crawler.h"

class Board {
private:
    std::vector<Crawler*> crawlers;
    std::vector<std::vector<std::list<Crawler*>>> grid;

public:
    Board();
    ~Board();

    void initializeFromFile(const std::string& filename);
    void displayAllBugs() const;
    void findBugById(int id) const;
    void tapBoard();
    void displayLifeHistories() const;
    void writeLifeHistoryToFile(std::ofstream& outFile) const;

    void updateBoard();
    void displayAllCells() const;

    void resolveFightsInCell(int x, int y);

    void runSimulation();
    // Utility
    const std::vector<Crawler*>& getCrawlers() const { return crawlers; }
};

#endif // BOARD_H
