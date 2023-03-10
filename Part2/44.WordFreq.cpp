/* Take a sentence and a word as input from user. 
   Then count the number of occurrences of the word in the sentence. */

#include <iostream>
#include <string>

using namespace std;

int numOccurances(string sentence, string word)
{
    int sentenceLen = sentence.size();
    int wordLen = word.size();

    int count = 0;
    char initial = word[0];
    for (int i = 0; i < sentenceLen; i++)
    {
        if (sentence[i] != initial)
            continue;

        // Initial encountered: following word is a possible match
        int j = 0;
        while ( (i < sentenceLen) && (j < wordLen) && (word[j++] == sentence[i++]) );
        if (j == wordLen) {
            count++;
        }
    }
    return count;
}

int main()
{   
    string sentence;
    do {
        cout << "Enter a sentence: ";
        getline(cin, sentence);
    } while (sentence.size() <= 0);

    string word;
    do {
        cout << "Enter a word to search for in the sentence: ";
        cin >> word;
    } while (word.size() <= 0);

    cout << word << " occurs " << numOccurances(sentence, word) << " times." << endl;
}
