//
// Created by arago on 31/03/2025.
//
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Crawler.h"

class Board {
private:
    std::vector<Crawler*> crawlers;  // Store crawlers dynamically

public:
    Board();
    ~Board();
    void initializeFromFile(const std::string& filename);
    void displayAllBugs() const;
    void findBugById(int id) const;
    void tapBoard();  // Move all bugs
};

#endif
