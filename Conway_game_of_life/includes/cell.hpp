#include<iostream>
#include "common.hpp"

class Cell
{
    bool _active;
public:
    // The cell is initialized as inactive
    Cell() : _active(false) {}

    // Activate the cell
    void activate();

    // Inactivate the cell
    void inactivate();

    // Check if cell is active
    bool isActive();

    // Draw cell
    void draw(int row, int col);
private:
    EscapeCodesANSI _ansi;
};
