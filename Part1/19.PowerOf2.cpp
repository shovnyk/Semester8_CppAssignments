/* Take a number and check whether it is a power of 2 or not. */

#include <iostream>

using namespace std;

#define LSB(number) (number & 1)

int main()
{
    // assume user input to be a 32 bit unsigned integer 
    cout << "Enter a number to check if a power of 2: ";

    unsigned int number; // unsigned to ensure logical right shift, not arithmetic (fill in 0s)
    cin >> number;

    // handle edge case: when input = 0
    if (number == 0)
    {
        cerr << "0 is not a power of 2." << endl;
        return 1;
    }

    unsigned int copy = number;

    while (LSB(number) != 1)  // edge case: when number = 0
        number = number >> 1; // logical right shift number by 1 bit every loop
    bool isPowerOf2 = (number == 1);

    cout << copy << (isPowerOf2? " is " : " isn't ") << "a power of two" << endl;
    return 0;
}
