/* Take a hexadecimal number string as input from the user.
   Convert it to decimal and print it to the console. */

#include <iostream>
#include <string>

using namespace std;

int decimalEquivalent(char hexDigit)
{
    if (hexDigit >= '0' && hexDigit <= '9')
        return hexDigit - '0';
    if (hexDigit >= 'A' && hexDigit <= 'F')
        return (10 + hexDigit - 'A');
    if (hexDigit >= 'a' && hexDigit <= 'f')
        return (10 + hexDigit - 'a');
    else
        return -1;
}

int hexadecimalToDecimal(string hexNumber, bool* valid)
{
    int decimal = 0;
    for (char hexDigit : hexNumber) {
        int decDigit = decimalEquivalent(hexDigit);
        if (decDigit == -1) {
            *valid = false;
            return -1;
        }
        decimal = decimal*16 + decDigit;
    }
    *valid = true;
    return decimal;
}

int main()
{
    string number;
    cout << "Enter a number in hexadecimal: ";
    cin >> number;
    bool valid;
    int decimal = hexadecimalToDecimal(number, &valid);
    if (!valid) {
        cerr << "Invalid hex number." << endl;
        return 1;
    }
    cout << "Decimal = " << decimal << endl;
}
