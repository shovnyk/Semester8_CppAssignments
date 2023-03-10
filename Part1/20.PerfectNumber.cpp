/* 
    Take a number and find the sum of all the factors of it. 
    Now check whether the sum is equal to the original number or not.
    If equal print "Perfect Number".
    Otherwise print "Not Perfect".
    Eg: factors(6) = 1, 2, 3
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
        if (number%i == 0)
            sum += i;
    return (sum == number);
}

int main()
{
    int number;
    cout << "Enter a number to check if Perfect: ";
    cin >> number;

    cout << number << (isPerfect(number)? " is " : " isn't ");
    cout << "a Perfect number." << endl;
}
