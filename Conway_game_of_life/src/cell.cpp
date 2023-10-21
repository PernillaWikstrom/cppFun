#include "cell.hpp"

using namespace std;

void Cell::activate()
{
    _active = true;
}

void Cell::inactivate()
{
    _active = false;
}

bool Cell::isActive()
{
    return _active;
}

void Cell::draw(int row, int col)
{
    cout << _ansi.escape << row + 1 << _ansi.semiColon << col + 1 << _ansi.cursor;
    cout << (isActive() ? cellIsActive : cellIsInactive) << endl;
}
