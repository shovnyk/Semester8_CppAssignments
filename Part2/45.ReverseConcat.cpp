/*  Take 2 strings as input from the user. Now concatenate them into a third
    string and then print it in reversed way.
    Example: String 1:-GOOD String 2:-MORNING
    Output:- GNINROM DOOG */

#include <iostream>
#include <string>
#include <algorithm>

std::string reverseConcat(std::string string1, std::string string2)
{
    std::reverse(string1.begin(), string1.end());
    std::reverse(string2.begin(), string2.end());
    string2 += string1;
    return string2;
}

int main()
{
    std::string string1;
    std::string string2;
    std::cout << "Enter a string: ";
    std::getline(std::cin, string1);
    std::cout << "Enter a string: ";
    std::getline(std::cin, string2);

    std::string reversedConcatenated = reverseConcat(string1, string2);

    std::cout << "Result = " << reversedConcatenated << std::endl;
}
