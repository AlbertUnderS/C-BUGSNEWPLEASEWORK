#include <iostream>
#include "Board.h"

int main() {
    Board board;  // Create a Board instance

    // Initialize the board with bugs from the file
    board.initializeFromFile("crawler-bugs.txt");

    // Display all bugs on the board
    board.displayAllBugs();

    return 0;
}

