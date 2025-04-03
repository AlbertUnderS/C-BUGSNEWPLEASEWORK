#include <iostream>
#include "Board.h"

int main() {
    Board board;
    board.initializeFromFile("C:/Users/arago/CLionProjects/CA3-CPP-A.A/crawler-bugs.txt");

    while (true) {
        std::cout << "\nChoose an option:\n"
                  << "1. Display all bugs\n"
                  << "2. Find a bug by ID\n"
                  << "3. Tap the bug board\n"
                  << "4. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                board.displayAllBugs();
            break;
            case 2: {
                int id;
                std::cout << "Enter bug ID: ";
                std::cin >> id;
                board.findBugById(id);
                break;
            }
            case 3:
                board.tapBoard();
            break;
            case 4:
                std::cout << "Exiting program.\n";
            return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
