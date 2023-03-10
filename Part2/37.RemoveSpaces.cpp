/* Take a sentence as input from the user and remove all spaces from it */

#include <iostream>
#include <string>

using namespace std;

char* removeAllSpaces(string sentence)
{
    int i = 0;
    int j = 0;
    char* newSentence = new char[sentence.size()]; // Atmost as long as original
    while (i < sentence.size())
    {
        while (sentence[i] == ' ') { i++; }
        newSentence[j++] = sentence[i++];

    }
    for (; j < sentence.size(); j++) { // Pad unfilled spaces with null bytes
        newSentence[j] = '\0';
    }
    return newSentence;
}

char* removeExtraSpaces(string sentence)
{
    int i = 0;
    int j = 0;
    char* newSentence = new char[sentence.size()];
    while (i < sentence.size())
    {
        newSentence[j++] = sentence[i];
        if (sentence[i] == ' ') {
            while ((++i) < sentence.size() && sentence[i] == ' ');
        }
        else {
            i++;
        }
    }
    for (; j < sentence.size(); j++) {
        newSentence[j] = '\0';
    }
    return newSentence;
}

int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
   
    char* sentenceSpacesRemoved = removeExtraSpaces(sentence);
    cout << "After removing spaces: ";
    cout << sentenceSpacesRemoved << endl;

    delete[] sentenceSpacesRemoved;
}
/* To test if this function is working properly, use the Unix program
   `od` with the flag `-x` or `-c` and `--endian=big`. */
