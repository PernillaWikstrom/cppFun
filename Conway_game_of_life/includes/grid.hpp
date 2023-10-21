#include<iostream>

#include "cell.hpp"

class Grid
{
    // The grid consist of a 2D grid
    Cell _cells[maxRows + 2][maxColumns + 2];
public:
    // With a probability of a cell being populated, populate grid.
    void populateRandomly(const float probability);

    // Display the full grid
    void display();

    // Go through the grid of the current generation and update with next generation
    void update(const Grid& next);

    // Activate cell in grid
    void populate(int row, int column);

    // Count active neibours in a neighbourhood of 1 grids distance.
    int getNumberActiveNeighbours(int row, int column);

    // An active cell survives if there are between
    // [mininum_neighbours, maximum_neighbours] active neighbours
    bool isActiveCellSurvivable(int numberActiveNeighbours);

    // An inactive cell is excitable if it has exactly maximum_neighbours active neighbours
    bool isInactiveCellExcitable(int numberActiveNeighbours);

    // Check if cell in grid is active
    bool isActive(int row, int column);

private:
    EscapeCodesANSI _ansi;
};

// Calculate state transition of cells based on current generation
// and populate the grid of next generation
void calculateStateTransition(Grid& currentGeneration, Grid &nextGeneration);
