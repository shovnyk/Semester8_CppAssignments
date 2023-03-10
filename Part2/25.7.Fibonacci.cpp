/* Print the Fibonacci series upto n terms.
   n will be given by the user. */

#include <iostream>

using namespace std;

// Get the n'th term in the Fibonacci series
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Memoization avoids redudant computation and improves time complexity
#define MEMO_SIZE 1000 // Upto 1000 terms can be copmuted
#define EMPTY -1
int memo[MEMO_SIZE];

int fibonacciMemoized(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (memo[n] == EMPTY)
        memo[n] = fibonacciMemoized(n - 1) + fibonacciMemoized(n - 2);
    return memo[n];
}

int main()
{
    // Initialize the memo to 'empty'
    for (int i = 0; i < MEMO_SIZE; i++) {
        memo[i] = EMPTY;
    }

    int number = 0;
    while (number < 2) {
        cout << "Enter number to print Fibonacci sequence upto (> 2): ";
        cin >> number;
    }
    cout << "Fibonacci series: ";
    for (int i = 0; i < number; i++) {
        cout << fibonacciMemoized(i) << " ";
    }
    cout << endl;
}
