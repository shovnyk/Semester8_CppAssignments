/* Take a decimal number as input from the user and convert it to hexadecimal. */

#include <iostream>

using namespace std;

int main() 
{
    unsigned int decimal; // upto 32-bits => 8 hexadecimal digits needed max
    cout << "Enter a decimal number to convert to hexadecimal: ";
    cin >> decimal;

    char buffer[9] = {0}; // 8 byte representation + 1 null byte string terminator
    char* hexadecimal = buffer + 8; // start from last slot in buffer
    do {
        hexadecimal--; // go back filling slots
        int hexdigit = decimal & 0x0000000F; // extract last 4 bits (same as % 16)
        if (hexdigit <= 9)
            *hexadecimal = '0' + hexdigit;
        else
            *hexadecimal = 'A' + (hexdigit - 10);
        decimal >>= 4;  // shift right by 4 bits logically (same as /= 16)
    } while (decimal); // while there are bits to extract

    cout << "Hexadecimal = " << hexadecimal << endl;
}
