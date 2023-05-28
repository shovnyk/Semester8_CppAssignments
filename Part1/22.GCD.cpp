/* 
   Find the GCD (greatest common divisor) of 2 numbers.
   Hence find their LCM.
*/

#include <iostream>

using namespace std;

// GCD using Iteration
int gcdIteration(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// GCD using Euclidean Algorithm (Recursion)
int gcdRecursive(int /* smaller number: */ a, int /* larger number: */ b)
{
    int remainder = b % a;
    if (remainder == 0)
        return a;
    return gcdRecursive(remainder, a);
}

int main()
{
    int A, B;
    cout << "Enter two numbers to find the GCD of: ";
    cin >> A >> B;

    // gcdRecursive() expects first argument to be smaller, swap before passing if needed
    if (A > B) { 
        int temp = A;
        A = B;
        B = temp;
    }

    // Compute the GCD
    int G = gcdIteration(A, B);

    // LCM * GCD = product of numbers
    int L = (A*B)/G;

    cout << "GCD = " << G << endl;
    cout << "LCM = " << L << endl;
}
