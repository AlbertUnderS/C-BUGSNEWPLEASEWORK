#include <iostream>
#include <vector>
#include <cstdlib>  // For random numbers
#include <ctime>
#include "Crawler.h"

int main() {
    // Seed random number generator
    std::srand(std::time(nullptr));

    // Create a few test Crawler objects
    std::vector<Crawler*> bugs;
    bugs.push_back(new Crawler(101, 0, 0, Direction::East, 5));
    bugs.push_back(new Crawler(102, 9, 0, Direction::South, 3));
    bugs.push_back(new Crawler(103, 9, 9, Direction::West, 2));

    // Display initial state of bugs
    std::cout << "Initial Bug States:\n";
    for (const auto& bug : bugs) {
        bug->display();
    }

    // Simulate a few movements
    std::cout << "\nAfter Moving:\n";
    for (auto& bug : bugs) {
        bug->move();
        bug->display();
    }

    // Clean up dynamically allocated memory
    for (auto& bug : bugs) {
        delete bug;
    }
    bugs.clear();

    return 0;
}
