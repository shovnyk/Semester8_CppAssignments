/* Take a number as input from user. 
   Now check whether all the digits of the number are unique or not 
   (i.e each digit must occur only once). */

#include <iostream>

using namespace std;


bool hasUniqueDigits(int number)
{
    bool present[10] = {false};
    do {
        int digit = number%10;
        if (present[digit]) {
            return false;
        }
        else {
            present[digit] = true;
        }
        number /= 10;
    } while (number);
    return true;
}

int main()
{
    int number;
    cout << "Enter a number to check if its digits are unique: ";
    cin >> number;
    cout << number << (hasUniqueDigits(number)? " has " : " does not have ") << "unique digits." << endl;
}
