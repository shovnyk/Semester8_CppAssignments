/* Take 2 strings from user and implement the functionality of strcmp() function
   on them by your own logic. */

#include <iostream>
#include <string>

int myStrcmp(const std::string s1, const std::string s2) {
    int minlen;
    if (s1.size() >= s2.size()) {
        minlen = s1.size();
    }
    else {
        minlen = s2.size();
    }
    int i;
    for (i = 0; i < minlen; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

int main()
{
    std::string first;
    std::string second;
    std::cout << "Enter first string: ";
    std::getline(std::cin, first);
    std::cout << "Enter a second string: ";
    std::getline(std::cin, second);
    int x = myStrcmp(first, second);
    if (x == 0) {
        std::cout << first << " = " << second << std::endl;
    }
   else if (x < 0) {
        std::cout << first << " < " << second << std::endl;
    }
    else {
        std::cout << first << " > " << second << std::endl;
    }
}
