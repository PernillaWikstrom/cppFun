#include "grid.hpp"

using namespace std;

void Grid::populateRandomly(const float probability)
{
    const int cutoff = RAND_MAX * probability;
    time_t now;
    now = 10;
    srand(now);

    for (int row = 1; row < maxRows; ++row) {
        for (int column = 1; column < maxColumns; ++column) {
            if (rand() / cutoff == 0) {
                populate(row, column);
            }
        }
    }
}

void Grid::populate(int row, int column)
{
    _cells[row][column].activate();
}

void Grid::display()
{
    cout << _ansi.escape + _ansi.home;
    for (int row = 1; row < maxRows; ++row) {
        for (int column = 1; column < maxColumns; ++column) {
            _cells[row][column].draw(row, column);
        }
    }
}

int Grid::getNumberActiveNeighbours(int row, int column)
{
    int gridDistance = 1;
    return _cells[row - gridDistance][column - gridDistance].isActive() +
                                _cells[row - gridDistance][column].isActive() +
                                _cells[row - gridDistance][column + gridDistance].isActive() +
                                _cells[row][column - gridDistance].isActive() +
                                _cells[row][column + gridDistance].isActive() +
                                _cells[row + gridDistance][column - gridDistance].isActive() +
                                _cells[row + gridDistance][column].isActive() +
                                _cells[row + gridDistance][column + gridDistance].isActive();
}

bool Grid::isActiveCellSurvivable(int numberActiveNeighbours)
{
    if (numberActiveNeighbours < mininum_neighbours || numberActiveNeighbours > maximum_neighbours)
    {
        return false;
    }

    return true;
}

bool Grid::isInactiveCellExcitable(int numberActiveNeighbours)
{
    if (numberActiveNeighbours == maximum_neighbours)
    {
        return true;
    }
    return false;
}


void Grid::update(const Grid& next)
{
    for (int row=0; row<=maxRows; row++)
    {
        for (int column=0; column<=maxColumns; column++)
        {
            _cells[row][column] = next._cells[row][column];
        }
    }
}

bool Grid::isActive(int row, int column)
{
    return _cells[row][column].isActive();
}

void calculateStateTransition(Grid& currentGeneration, Grid &nextGeneration)
{
    for (int row=0; row<=maxRows; row++){
        for (int column=0; column<=maxColumns; column++){

            int numberActiveNeighbours = currentGeneration.getNumberActiveNeighbours(row, column);
            int isCurrentCellActive = currentGeneration.isActive(row, column);

            if ((isCurrentCellActive && currentGeneration.isActiveCellSurvivable(numberActiveNeighbours)) ||
                (!isCurrentCellActive && currentGeneration.isInactiveCellExcitable(numberActiveNeighbours)))
            {
                nextGeneration.populate(row, column);
            }
        }
    }
    return;
}
