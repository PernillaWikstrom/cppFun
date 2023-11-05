
#include <vector>

#include "divisor.hpp"

using namespace std;

// Non-member function that is using a functor to tell weather element in vector is divisible
void findDivisibleElements(const vector<int>& vec, Divisible isDivisible) {
    for (auto elem: vec)
        if (isDivisible(elem))
            cout << elem << " is divisible\n";
}

int main() {
    vector<int> numbers{1, 4, 7, 11, 12, 23, 36};

    cout << "Input Vector: ";
    for (auto number : numbers)
        cout << number << ", ";
    cout << endl;

    Divisible divisible_by_three{2};
    cout << "Finding all elements that are divisible by " << divisible_by_three.getDivisor() << endl;
    findDivisibleElements(numbers, divisible_by_three);
}