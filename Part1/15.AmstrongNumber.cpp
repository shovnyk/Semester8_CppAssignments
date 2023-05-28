/* Take a number and check whether it is Armstrong or not. */

#include <iostream>

using namespace std;

bool isArmstrong(int number)
{
    int sum = 0;
    int copy = number;
    do {
        int digit = number % 10;
        sum += digit*digit*digit;
        number /= 10;
    } while (number);
    return (sum == copy);
}

int main()
{
    int number;

    cout << "Enter a number to check if Armstrong or not: ";
    cin >> number;

    cout << number << (isArmstrong(number)? " is " : " isn't ")
         << "an Armstrong number." << endl;
}
