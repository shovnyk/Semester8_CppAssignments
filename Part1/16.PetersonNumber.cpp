/* Take a number and check whether it is Peterson or not. */

#include <iostream>

using namespace std;

int factorial(int number)
{
    return number == 0? 1 : number*factorial(number - 1);
}

bool isPeterson(int number) 
{
    int sum = 0;
    int copy = number;
    do {
        int digit = number % 10;
        sum += factorial(digit);
        number /= 10;
    } while (number);
    return (sum == copy);
}

int main()
{
    int number;

    cout << "Enter a number to check if Peterson or not: ";
    cin >> number;

    cout << number << (isPeterson(number)? " is " : " isn't "); 
    cout << "a Peterson number." << endl;
}
