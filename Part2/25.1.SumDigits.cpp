/* Recursive function to calculate the sum of the digits of a number */
#include <iostream>

using namespace std;

int sumOfDigits(int number)
{
    if (number == 0)
        return 0;
    return (number % 10) + sumOfDigits(number/10);
}

int main()
{
    int number;
    cout << "Enter number to sum the digits in : ";
    cin >> number;
    cout << "Sum of digits = " << sumOfDigits(number) << endl;
}
