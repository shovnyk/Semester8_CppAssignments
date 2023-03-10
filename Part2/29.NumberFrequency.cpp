/* Count the number of occurances of a word in user input using an unordered
   map data structure, part of the C++ Standard Template Library (STL). */


#include <iostream>         // std::cout, std::cerr 
#include <unordered_map>    // std::unordered_map
#include <cstdlib>          // std::sscanf

int main(int argc, char* argv[])
{
    // Make sure user has enter some input.
    if (argc < 2) {
        std::cerr << argv[0] << ": must enter at least 1 integer." << std::endl;
        return 1;
    }

    // Take user input and put into map, incrementing value when appropriate.
    int number;
    std::unordered_map<int, int> umap;
    for (int i = 1; i < argc; i++) {
        if (std::sscanf(argv[i], "%d", &number) != 1) {
            std::cerr << argv[i] << " is not a number, skipping." << std::endl;
            continue;
        }
        if (umap.count(number) > 0) {
            umap[number] += 1;
        }
        else {
            umap[number] = 1;
        }
    }

    // Print out the number of occurances.
    for (auto pair : umap) {
        std::cout << pair.first << " occurs " << pair.second << " times." << std::endl;
    }

}

