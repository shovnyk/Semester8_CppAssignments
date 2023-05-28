/* Take 3 numbers and print the highest */

#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    int z;

    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    int maxXY = x > y ? x : y;
    int maxInt = maxXY > z ? maxXY : z;
    
    cout << "Maximum of the three numbers = " << maxInt << endl;
}
