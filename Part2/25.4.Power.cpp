/* Determine the value of a^b */

#include <iostream>

using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    return a*power(a, b-1);
}

int main()
{
    int a, b;
    cout << "Enter a and b:" << endl;
    cin >> a >> b;
    cout << "a^b = " << power(a, b) << endl;
}
