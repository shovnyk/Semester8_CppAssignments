/* Take a number and reveser it. 
   Now check whether the original number and the reversed number are equal or not. */

#include <iostream>

using namespace std;

int reversedNumber(int number)
{ 
    // copy of actual argument is made in formal argument (call by value)
    int reversed = 0;
    do {
        reversed = reversed*10 + number%10;
        number /= 10;
    } while (number);
    return reversed;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    int reversed = reversedNumber(number);

    cout << "Original: " << number << endl;
    cout << "Reversed: " << reversed << endl;

    if (reversed == number) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }
}
