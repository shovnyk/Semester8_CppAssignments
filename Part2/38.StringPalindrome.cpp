/* Take a word and check whether it is a palindrome. */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int front = 0;
    int back = s.size() - 1;
    while (front <= back) {
        if (s[front++] != s[back--])
            return false;
    }
    return true;
} 

int main()
{
    string word;
    cout << "Enter a word to check if a palindrome: ";
    cin >> word;
    
    cout << word << (isPalindrome(word)? " is " : " isn't ") << "a palindrome." << endl;
}
