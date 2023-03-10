/* Calculate the gcd of 2 numbers. */

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int remainder = b % a;
    if (remainder == 0)
        return a;
    return gcd(remainder, a);
}

int main()
{
    int A, B;
    cout << "Enter two numbers:" << endl;
    cin >> A >> B;
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    }
    cout << "GCD = " << gcd(A, B) << endl;
}
