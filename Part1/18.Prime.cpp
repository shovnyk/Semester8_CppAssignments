/* Take a number and check if it is a Prime */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number)
{
    if (number < 2)
        return false;
    int upto = floor(sqrt(number));
    for (int i = 2; i <= upto; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int number;
    cout << "Enter a number to check if prime: ";
    cin >> number;
    cout << number << (isPrime(number)? " is " : " isn't ");
    cout << "a prime number." << endl;
}
