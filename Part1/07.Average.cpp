/* Calculate the average of all the numbers between m and n.
   m and n will be given by the user as input through the keyboard */

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    float sum, avg;
    cout << "Enter lower limit (an integer): ";
    cin >> m;
    cout << "Enter upper limit (an integer): ";
    cin >> n;
    sum = 0;
    for (int i = m; i <= n; i++) 
        sum += i;
    avg = sum/(n - m);
    cout << "Average = " << avg << endl;
}
