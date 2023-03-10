/* Find the sum of the series: 1 + 2 + 3 + 4 + 5 + ...n */

#include <iostream>

using namespace std;

int series(int n)
{
    if (n == 0)
        return 0;
    return n + series(n - 1);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Sum = " << series(n) << endl;
}
