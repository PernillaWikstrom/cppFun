#include "grid.hpp"
#include "ansi_escapes.hpp"

using namespace std;

int main()
{
    EscapeCodesANSI ansi;
    Grid currentGeneration;
    currentGeneration.populateRandomly(0.2f);

    while (true) {

        currentGeneration.display();

        // Wait for user to press the return key
        cin.get();

        // Create a new grid for the next generation
        Grid nextGeneration;
        calculateStateTransition(currentGeneration, nextGeneration);

        currentGeneration.update(nextGeneration);
    }

    // Move cursor to bottom of screen
    cout << ansi.escape << 0 << ansi.semiColon << maxRows - 1 << ansi.cursor;
}
