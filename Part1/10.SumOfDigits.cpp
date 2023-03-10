/* Take a number and calculate the sum of its digits */

#include <iostream>

using namespace std;

int main()
{
    int number;
    int sum;

    cout << "Enter a number: ";
    cin >> number;

    sum = 0;
    do {
        sum += number % 10;
        number /= 10;
    } while (number); 

    cout << "Sum of digits = " << sum << endl;
}
