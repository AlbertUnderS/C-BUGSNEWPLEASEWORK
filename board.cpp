//
// Created by arago on 31/03/2025.
//

#include "Board.h"

Board::Board() {
    // Initializing the board with no crawlers
}

Board::~Board() {
    // Clean up dynamically allocated Crawler objects
    for (auto& crawler : crawlers) {
        delete crawler;
    }
    crawlers.clear();
}

void Board::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open the file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char type;
        int id, x, y, dir, size;

        // Parse the data for each bug (Crawler)
        ss >> type >> id >> x >> y >> dir >> size;

        if (type == 'C') {
            // Create a new Crawler dynamically
            Crawler* newCrawler = new Crawler(id, x, y, static_cast<Direction>(dir), size);
            crawlers.push_back(newCrawler);  // Add to the crawlers vector
        }
    }

    file.close();
}

void Board::displayAllBugs() const {
    if (crawlers.empty()) {
        std::cout << "No bugs available on the board!" << std::endl;
        return;
    }

    std::cout << "List of all bugs on the board:" << std::endl;
    for (const auto& crawler : crawlers) {
        crawler->display();  // Use the display method of Crawler class
    }
}

