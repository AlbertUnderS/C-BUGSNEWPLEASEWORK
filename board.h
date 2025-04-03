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
    std::vector<Crawler*> crawlers;  // List of Crawler objects on the board
public:
    // Method to initialize the board from the file
    void initializeFromFile(const std::string& filename);

    // Method to display all bugs on the board
    void displayAllBugs() const;
};

#endif

