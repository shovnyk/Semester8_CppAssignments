/* Take a number and print its factorial. */

#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter the number to print the factorial of: ";
    cin >> number;

    // Compute factorial iteratively: factorials can grow large (hence long)
    long unsigned int factorial = 1; // unsigned has longer positive range

    for (int i = 1; i <= number; i++)
        factorial *= i; // Will be cast to long unsigned int

    cout << number << "! = " << factorial << endl;
}
