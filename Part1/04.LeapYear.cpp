/* Check if a year is a leap year. */

#include <iostream>

using namespace std;

int main()
{
    int year;
    bool isLeap;

    cout << "Enter the year: " << endl;
    cin >> year;

    isLeap = year % 4 == 0;
    cout << year << (isLeap? " is " : " isn't ") << "a leap year." << endl;
}
