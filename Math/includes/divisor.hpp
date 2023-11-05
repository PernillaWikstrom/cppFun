#include <iostream>

using namespace std;

class Divisible
{
private:
    int _defaultDivisor{1};
    uint _divisor{unsigned(_defaultDivisor)};

public:
    // Initialize the class
    Divisible(uint divisor): _divisor(divisor) {
        if (divisor == 0)
        {
            cout << "Divisor must be greater than zero, using defaultDivisor = " << _defaultDivisor << endl;
            _divisor = _defaultDivisor;
        }
    }

    // The functor checks if a number is divisible
    bool operator() (int num) {
        return (num % _divisor == 0);
    }

    // Get the value of the divisor
    int getDivisor(){return _divisor;}
};
