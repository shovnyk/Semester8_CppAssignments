/* Take a sentence from user as input. 
   Then count the number of vowels, digits, and words present in it. */

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        || (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

struct SentenceStats
{
    int numVowels;
    int numDigits;
    int numWords;
};

SentenceStats getStats(string sentence)
{
    sentence += ' ';
    SentenceStats s = {0, 0, 0};
    char current, next;
    for (int i = 0; i < sentence.size()-1; i++)
    {
        current = sentence[i];
        next = sentence[i + 1];
        if (current == ' ') {
            continue;
        }
    
        if (isVowel(current))
            s.numVowels++;

        else if (isDigit(current))
            s.numDigits++;

        if (next == ' ')
            s.numWords++;
    }
    return s; // return copy of the struct (copy elison may apply)
}

int main()
{
    string sentence;
    do {
        cout << "Enter a sentence (with at least one word): ";
        getline(cin, sentence);
    } while (sentence.size() <= 0);

    SentenceStats s = getStats(sentence);

    cout << "Number of vowels = " << s.numVowels << endl;
    cout << "Number of digits = " << s.numDigits << endl;
    cout << "Number of words  = " << s.numWords  << endl;
}
