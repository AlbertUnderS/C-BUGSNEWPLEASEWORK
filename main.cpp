#include <iostream>
#include "Board.h"

int main() {
    Board board;  // Create a Board instance
    board.initializeFromFile("C:/Users/arago/CLionProjects/CA3-CPP-A.A/crawler-bugs.txt");

    std::cout << "Displaying all bugs on the board:" << std::endl;
    board.displayAllBugs();  // Display the bugs

    return 0;
}

