#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// Function to return the official golf term for a score relative to par
std::string getScoreTerm(int strokes, int par) {
    int relative = strokes - par;
    if (strokes == 1) return "Hole-in-One!";
    switch (relative) {
        case -3: return "Albatross";
        case -2: return "Eagle";
        case -1: return "Birdie";
        case  0: return "Par";
        case  1: return "Bogey";
        case  2: return "Double Bogey";
        default: return relative > 2 ? "Triple Bogey+" : "Excellent Score";
    }
}

int main() {
    std::cout << "=== C++ Golf Scorecard Calculator ===\n\n";

    int totalHoles;
    std::cout << "Enter number of holes played (e.g., 9 or 18): ";
    std::cin >> totalHoles;

    std::vector<int> pars;
    std::vector<int> strokes;

    // Collect data for each hole
    for (int i = 1; i <= totalHoles; ++i) {
        int p, s;
        std::cout << "\nHole " << i << " Par: ";
        std::cin >> p;
        std::cout << "Hole " << i << " Strokes taken: ";
        std::cin >> s;

        pars.push_back(p);
        strokes.push_back(s);

        std::cout << "Result: " << getScoreTerm(s, p) << "\n";
    }

    // Calculations
    int totalPar = std::accumulate(pars.begin(), pars.end(), 0);
    int totalStrokes = std::accumulate(strokes.begin(), strokes.end(), 0);
    int finalScore = totalStrokes - totalPar;

    // Output final summary
    std::cout << "\n====================================\n";
    std::cout << "FINAL SCORECARD SUMMARY\n";
    std::cout << "====================================\n";
    std::cout << "Total Course Par: " << totalPar << "\n";
    std::cout << "Your Total Strokes: " << totalStrokes << "\n";
    
    if (finalScore == 0) {
        std::cout << "Overall Performance: Even Par (E)\n";
    } else if (finalScore < 0) {
        std::cout << "Overall Performance: " << finalScore << " Under Par (-)\n";
    } else {
        std::cout << "Overall Performance: +" << finalScore << " Over Par (+)\n";
    }
    return 0;
}