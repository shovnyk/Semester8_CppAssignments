/* Take a and b as input from the user. Now calculate a^b */

#include <iostream>
#include <cmath> // Equivalent to math.h in C

using namespace std;

int main()
{
    double a;
    double b;
    double result = 0.0;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    result = pow(a, b);
    cout << "a^b = " << result << endl;
}
