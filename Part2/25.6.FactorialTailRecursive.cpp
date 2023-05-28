/* Calculate the factorial of a number using tail-recursion  */

#include <iostream>

using namespace std;

long unsigned int factorial(int number)
{
    if (number == 0) return 1LU;
    // Tail recursion is when the recursive call is the last statement in a function.
    // Tail recursion allows the compiler to optimize the recursive function call into a while true loop for more efficiency.
    return number*factorial(number - 1);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << number << "! = " << factorial(number) << endl;
}
