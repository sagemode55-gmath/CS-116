#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct HoleData {
    int holeNumber;
    int par;
    int strokes;
};

// Function to determine the scoring term based on strokes vs par
std::string getScoreTerm(int strokes, int par) {
    if (strokes == 1) return "Hole-in-One";
    int difference = strokes - par;
    switch (difference) {
        case -3: return "Albatross";
        case -2: return "Eagle";
        case -1: return "Birdie";
        case  0: return "Par";
        case  1: return "Bogey";
        case  2: return "Double Bogey";
        case  3: return "Triple Bogey";
        default: return (difference > 3) ? "+" + std::to_string(difference) + " Bogey" : std::to_string(difference);
    }
}

int main() {
    std::string filename;
    std::cout << "Enter the golf data input filename: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::vector<HoleData> roundData;
    int hole, par, strokes;
    int totalPar = 0;
    int totalStrokes = 0;

    // Read data format: Hole Number, Par, Strokes
    while (inputFile >> hole >> par >> strokes) {
        roundData.push_back({hole, par, strokes});
        totalPar += par;
        totalStrokes += strokes;
    }
    inputFile.close();

    if (roundData.empty()) {
        std::cout << "No data found in the file." << std::endl;
        return 0;
    }

    // Print scorecard header
    std::cout << "\n================ GOLF SCORECARD ================\n";
    std::cout << std::left << std::setw(8) << "Hole" 
              << std::setw(8) << "Par" 
              << std::setw(10) << "Strokes" 
              << "Result\n";
    std::cout << "------------------------------------------------\n";

    // Print individual hole results
    for (const auto& record : roundData) {
        std::cout << std::left << std::setw(8) << record.holeNumber 
                  << std::setw(8) << record.par 
                  << std::setw(10) << record.strokes 
                  << getScoreTerm(record.strokes, record.par) << "\n";
    }

    // Print summary calculations
    std::cout << "------------------------------------------------\n";
    std::cout << std::left << std::setw(8) << "TOTAL" 
              << std::setw(8) << totalPar 
              << std::setw(10) << totalStrokes;
    
    int finalDiff = totalStrokes - totalPar;
    if (finalDiff == 0) {
        std::cout << "Even Par\n";
    } else if (finalDiff > 0) {
        std::cout << "+" << finalDiff << " Over Par\n";
    } else {
        std::cout << finalDiff << " Under Par\n";
    }
    std::cout << "================================================\n";

    return 0;
}
