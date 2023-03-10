/* Take a number in binary and convert it to decimal. */

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number in binary to convert to decimal (upto 32 bits): ";

    int binary;
    cin >> binary;

    int decimal = 0;
    int mask = 1;
    while (binary) {
        int bit = binary % 10;

        if (bit == 1)   // if '1', then set bit in the appropriate position
            decimal |= mask;
        mask = mask << 1;

        binary /= 10;
    }

    cout << "Decimal = "<< decimal << endl;
}
