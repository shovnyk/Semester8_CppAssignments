/* Take a number in decimal and convert it to binary. */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    unsigned int decimal;
    
    cout << "Enter a number in decimal to convert to binary (max 32 bits): ";
    cin >> decimal;

    char binary[33] = {0};
    char* ptr = binary + 32;

    // Numbers are already stored in memory in binary.
    // Take advantage of that with bitwise operators.
    int bit;
    do {
        ptr--;
        bit = (decimal & 1);
        *ptr += '0' + bit;
        decimal = decimal >> 1; // unsigned ensures logical right shift so number can become zero
    } while (decimal);

    cout << "Binary = " << ptr << endl;
}
