/* 
   Find the GCD (greatest common divisor) of 2 numbers.
   Hence find their LCM.
*/

#include <iostream>

using namespace std;

// GCD using Euclidean Algorithm (Recursion)
int gcd(int /* smaller number: */ a, int /* larger number: */ b)
{
    int remainder = b % a;
    if (remainder == 0)
        return a;
    return gcd(remainder, a);
}

int main()
{
    int A, B;
    cout << "Enter two numbers to find the GCD of: " << endl;
    cin >> A >> B;

    // gcd() expects first argument to be smaller, swap before passing if needed
    if (A > B) { 
        int temp = A;
        A = B;
        B = temp;
    }
    int G = gcd(A, B);

    // LCM * GCD = product of numbers
    int L = (A*B)/G;

    cout << "GCD = " << G << endl;
    cout << "LCM = " << L << endl;
}
