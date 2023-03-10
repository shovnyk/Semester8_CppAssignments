/* 
   Take 10 names and sort them into ascending order.
   Use LEXICOGRAPHIC SORT aka dictionary sort where the ascii values of
   alphabets are compared.

   Note: std::string allows direct comparison of string objects using
   relational operators which have been overloaded for the class in the
   standard C++ library. Yet we have decided to not make use of that
   functionality to demonstrate the idea behind lexicographical comparison by
   providing our own implementation.
*/

#include <iostream>
#include <string>

using namespace std;

const int NUM_NAMES = 10;

int compareStrings(string a, string b) // Lexicographically
{
    // Returns:
    //  >0 if string a is "greater than" string b
    //  <0 if string a is "lesser than" string b
    //   0 if string a is "equal to" string b
    int aLen = a.size();
    int bLen = b.size();
    int minLen = (aLen < bLen) ? aLen : bLen;
    for (int i = 0; i < minLen; i++)
    { // Compare character ascii values one by one as many times as shorter string
        if (a[i] > b[i]) 
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
    return aLen - bLen; // If all characters so far are equal, longer string wins
}

void sortStrings(string str[], int len) // Use bubble sort
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (compareStrings(str[j], str[j + 1]) > 0) {
                string tempStr = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tempStr;
            }
        }
    }
}

void printStrings(string str[], int len)
{
    for (int i = 0; i < len; i++) {
        cout << str[i] << endl;
    }
}

int main()
{
    // Take input from user
    string names[NUM_NAMES];
    cout << "Enter " << NUM_NAMES << " names:" << endl;
    for (int i = 0; i < NUM_NAMES; i++) {
        getline(cin, names[i]);
    }

    // Sort array of strings, lexicographically
    sortStrings(names, NUM_NAMES);

    // Print sorted array of strings
    cout << "After sorting, the names are:" << endl;
    printStrings(names, NUM_NAMES);
}
