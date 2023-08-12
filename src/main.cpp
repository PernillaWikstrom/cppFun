#include "diamond.hpp"

using namespace std;

int main()
{
    Diamond myDiamond;
    int nRows, ret;
    cout<<"Enter the number (integer) of rows for the diamond pattern: ";
    cin>>nRows;

    ret = myDiamond.setNRows(nRows);
    if (ret < 0)
    {
        cout<< "Please choose an int > 0\n";
        return ret;
    }
    myDiamond.drawPattern();
    return 0;
}