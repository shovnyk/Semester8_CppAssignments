/* Take a number and check whether it is a power of 2 or not. */

#include <iostream>

using namespace std;

#define LSB(number) (number & 1)

int main()
{
    unsigned int number; // to ensure logical right shift, not arithmetic (fill in 0s)
    unsigned int copy;
    cout << "Enter a number to check if a power of 2: ";
    cin >> number;
    copy = number;

    while (LSB(number) != 1)
        number = number >> 1;
    bool isPowerOf2 = (number == 1);

    cout << copy << (isPowerOf2? " is " : " isn't ") << "a power of two" << endl;
}
