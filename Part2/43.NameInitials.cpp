/* 
   Take the name of a person as input from user.
   The print it in abbreviated form.
*/

#include <iostream>
#include <string>

using namespace std;

const int NAME_COMPONENTS = 10;

string initialize(string word)
{
    return word; // TODO: finish this
}

int main()
{
    cout << "Enter your name: ";
    string names[NAME_COMPONENTS];

    int i = 0;
    while (cin >> names[i++]);
    i--;

    string formattedName = "";
    for (int j = 0; j < i; j++) {
        if (j == (i - 1))
            formattedName += names[j];
        else
            formattedName += initialize(names[j]);
    }

    cout << formattedName << endl;
}
