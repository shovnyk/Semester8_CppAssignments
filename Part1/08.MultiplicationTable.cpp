/* Print the multiplication table of a number n. Take n as input from the user */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number to print the multiplication table for: ";
    cin >> n;

    cout.width(10);
    for (int i = 1; i <= n; i++)
    {
        cout << n << " x " << i << " = " << n*i << endl;
    }
}
