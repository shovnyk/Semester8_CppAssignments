/* Perform swapping without a third variable. */

#include <iostream>

using namespace std; // Import cout, cin and endl from std namespace

int main()
{
    // Declare variables
    int x;
    int y;

    // Get user input
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    // Swap without a third variable
    x = x + y;
    y = x - y;
    x = x - y;

    // Print swapped results
    cout << "After swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
