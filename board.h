//
// Created by arago on 31/03/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Crawler.h"  // To use the Crawler class

class Board {
private:
    std::vector<Crawler*> crawlers;  // Store the bugs

public:
    // Constructor
    Board();

    // Destructor to clean up dynamic memory
    ~Board();

    // Initialize bugs from the file
    void initializeFromFile(const std::string& filename);

    // Display all the bugs
    void displayAllBugs() const;

    // Additional functions can be added later (e.g., move bugs, fight bugs, etc.)
};

#endif // BOARD_H
