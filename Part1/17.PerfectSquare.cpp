/* Check whether a number is perfect square or not. */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    cout << "Enter a number to check if a perfect square: ";
    cin >> number;

    int numSqrt = sqrt(number); // automatically floored due to integer truncation
    bool isPerfectSquare = (numSqrt*numSqrt) == number;

    cout << number << (isPerfectSquare? " is " : " isn't ");
    cout << "a perfect square." << endl;
}
