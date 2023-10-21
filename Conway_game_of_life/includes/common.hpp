#include<iostream>

using namespace std;

// ANSI control command
struct EscapeCodesANSI
{
    // Escape
    string escape  = "\x1b[";
    // Clears the screen and returns the cursor to the "home" position
    string home = "2J";
    // Move cursor to bottom of screen
    string cursor = "H";
    // Semi colon
    string semiColon = ";";
};


// Active cell marker
const char cellIsActive{'X'};
// Inactive cell marker
const char cellIsInactive{' '};

// The grid consist of a 2D grid 80 x 24 elements
const int maxRows = 23;
const int maxColumns = 79;

// Minimum limit of neighbours
const int mininum_neighbours = 2;
// Maximum limit of neighbours
const int maximum_neighbours = 3;
