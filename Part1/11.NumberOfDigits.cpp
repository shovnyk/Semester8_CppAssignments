/* Take a number and calculate the number of digits present in it */

#include <iostream>

using namespace std;

int main()
{
    int number;
    int digitCount = 0;

    cout << "Enter a number: ";
    cin >> number;

    do {
        digitCount++;
        number /= 10;
    } while (number);
    // number becomes 0, either create copy or pass to function by value

    cout << "Number of digits = " << digitCount << endl;
}
