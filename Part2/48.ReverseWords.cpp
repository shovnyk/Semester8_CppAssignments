/* Take a string from user and print each word in reversed way. 
   The entire string will not be reversed in this process. */

#include <iostream>
#include <string>

using namespace std;

string reverse(string word)
{
    int len = word.size();
    string reversedWord(word);
    for (int i = 0; i < word.size(); i++) {
        reversedWord[len - 1 - i] = word[i];
    }
    return reversedWord;
}

int main()
{
    string sentence = "";
    string word;
    while (cin >> word) { // while there are words being input
        sentence += reverse(word) + " ";
    }
    cout << sentence << endl;
}
