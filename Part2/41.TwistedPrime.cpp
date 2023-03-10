/* 
   Take a number n as input in the main() method.
   Now call another method prime(n).
   It will check whether it is prime or not.
   Now reverse the number in main() method and call the prime(n) method again.
   If the reversed number is also prime, then print "Twisted Prime".
   Otherwise "Not Twisted Prime".
*/

#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n) // O(sqrt N)
{
    if (n < 2)
        return false;
    int upto = (int)floor(sqrt(n)); // Floating point exception => possible cause: division by zero
    for (int i = 2; i <= upto; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int reverse(int n)
{
    int num = 0;
    do {
        num = num*10 + n%10;
        n /= 10;
    } while (n);
    return num;
}

int main(void)
{
    int number;
    cout << "Enter a number to check if prime (and twisted prime): ";
    cin >> number;
    cout << number << (prime(number)? " is " : " isn't ") << "a prime number." << endl;

    if (prime(number) && prime(reverse(number))) {
        cout << "Twisted Prime" << endl;
    }
    else {
        cout << "Not Twisted Prime" << endl;
    }
    return 0;
}
