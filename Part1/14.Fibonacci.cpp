/* Generate the Fibonacci numbers upto n terms. n will be entered by the user. */

#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 1;
    int sum;
    int n;

    cout << "Enter the number of terms to printed in the Fibonacci sequence: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << x << " ";
        sum = x + y;
        x = y;
        y = sum;
    }
    cout << endl;
}
