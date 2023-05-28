/* Determine the number of digits of a number. */

#include <iostream>

using namespace std;

int digitCount(int number)
{
    if (number == 0)
        return 0;
    return 1 + digitCount(number/10);
}

int main()
{
    int number;
    cout << "Enter a number to determine the digits in: ";
    cin >> number;
    cout << "Number of digits in number: " << digitCount(number) << endl;
}
