/* Find the sum of series upto n terms, n input by the user in each case. */

#include <iostream>

using namespace std;

/* 1 + 4 + 9 + 16 + ...n terms */
int series1 (int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i*i;
    return sum;
}

/* 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) + ...n terms */
int series2(int n)
{
    int sum = 0;
    int grandSum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        grandSum += sum;
    }
    return grandSum;
}

/* 2 + 4 + 8 + 16 + 32 + 64 + ...n terms */
int series3(int n) 
{
    int num = 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num;
        num = num << 1; // left shift by 1 bit is faster than multiplication by 2
    }
    return sum;
}

/* 1*2 + 2*3 + 3*4 + 4*5 + ...n terms */
int series4(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i*(i + 1);
    }
    return sum;
}

/* x - x^2/2! + x^3/3! - x^4/4! + x^5/5!-...n terms (x = input) */
double series5(double x, int n)
{
    double sum = 0.0;
    double sign = -1.0;
    double xpow = 1.0; // x^0
    double fact = 1;    // 0! = 1

    for (int i = 1; i <= n; i++)
    {
        // Avoid computing upto i every time, build on previously computed value
        sign *= -1;
        xpow *= x;
        fact *= i;
        sum += sign*xpow/fact;
    }
    return sum;
}


int main()
{
    int n;

    cout << "Enter a value of n to compute series 1: ";
    cin >> n;
    cout << "Series 1 = " << series1(n) << endl;

    cout << "Enter a value of n to compute series 2: ";
    cin >> n;
    cout << "Series 2 = " << series2(n) << endl;

    cout << "Enter a value of n to compute series 3: ";
    cin >> n;
    cout << "Series 3 = " << series3(n) << endl;

    cout << "Enter a value of n to compute series 4: ";
    cin >> n;
    cout << "Series 4 = " << series4(n) << endl;

    cout << "Enter a value of n to compute series 5: ";
    cin >> n;
    double x;
    cout << "Enter the value of x for which to evaluate series 5: ";
    cin >> x;
    cout << "Series 5 = " << series5(x, n) << endl;
}

