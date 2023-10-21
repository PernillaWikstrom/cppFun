#include "diamond.hpp"

using namespace std;

int Diamond::setNRows(const int nRows)
{
    if ((nRows < 1))
    {
        return -1;
    }
    _nRows = nRows;
    return 0;
}

int Diamond::drawPattern()
{
    int nSpaces = _nRows - 1;
    int total_rows = (2 * _nRows) -1;
    int nDiamondsInRow = 1;
    for (int i=0; i < total_rows; i++)
    {
        // Set char for each column
        for (int j=0; j < total_rows; j++)
        {
            if(j >= nSpaces && j < nSpaces+nDiamondsInRow)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

        }
        // Adjust for next row
        if(i < _nRows - 1)
        {
            nSpaces--;
            nDiamondsInRow+= 2;
        }
        else if (i >= _nRows - 1)
        {
            nSpaces++;
            nDiamondsInRow-= 2;
        }
        cout<<endl;
    }
    return 0;
}
