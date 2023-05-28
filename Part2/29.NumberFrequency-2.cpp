/*
   A "more C++"-ish implementation without relying on C standard library functions.
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <stdexcept>

int main()
{
    // take user input and convert that to input string stream object for tokenization
    std::cout << "Enter a list of space-separated numbers: ";
    std::string input{};
    std::getline(std::cin, input);
    std::istringstream line{ input }; 

    std::string token;
    std::unordered_map<int, int> umap;
    while (line >> token)
    {
        // extract string tokens from input stream, attempt conversion to int
        // and store into dictionary
        try 
        {
            int number = std::stoi(token);
            if (umap.count(number) > 0)
            {
                // number has not been encountered before
                umap[number]++;
            }
            else
            {
                umap[number] = 1;
            }
        }
        catch (const std::invalid_argument&)
        {
            std::cerr << "Warning: " << token << " is not an integer, skipping" << std::endl;
        }
    }

    // print out the number of occurances
    for (auto pair : umap)
    {
        std::cout << pair.first << " occurs " << pair.second << " times." << std::endl;
    }
}
