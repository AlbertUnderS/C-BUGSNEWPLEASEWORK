#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Board.h"

int main() {
    Board board;
    boa"C:/Users/arago/CLionProjects/CA3_CPP_AA/crawler-bugs.txt");
rd.initializeFromFile(
    while (true) {
        board.updateBoard();
        std::cout << "\nChoose an option:\n"
                  << "1. Display all bugs\n"
                  << "2. Find a bug by ID\n"
                  << "3. Tap the bug board\n"
                  << "5. Display All Cells\n"
                  << "6. Run Simulation\n"
                  << "7. Exit\n";

        int choice;
        std::cin >> choice;

        // Declare variables before the switch statement
        std::time_t now = std::time(nullptr);
        std::tm* currentTime = std::localtime(&now);
        std::ostringstream fileName;
        std::ofstream outFile;

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
            case 5:
                board.displayAllCells();
            break;
            case 6:
                board.runSimulation();
            break;

            case 7:
                std::cout << "Exiting program.\n";

                // Create the filename with current date and time
                fileName << "bugs_life_history_"
                         << (currentTime->tm_year + 1900) << "_"
                         << std::setw(2) << std::setfill('0') << currentTime->tm_mon + 1 << "_"
                         << std::setw(2) << std::setfill('0') << currentTime->tm_mday << "_"
                         << std::setw(2) << std::setfill('0') << currentTime->tm_hour << "_"
                         << std::setw(2) << std::setfill('0') << currentTime->tm_min << "_"
                         << std::setw(2) << std::setfill('0') << currentTime->tm_sec
                         << ".txt";

                // Open the file for writing
                outFile.open(fileName.str());

                if (outFile) {
                    board.writeLifeHistoryToFile(outFile);
                    std::cout << "Life history written to: " << fileName.str() << std::endl;
                } else {
                    std::cerr << "Error: Could not create the file!" << std::endl;
                }

                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }



    }

    return 0;
}


