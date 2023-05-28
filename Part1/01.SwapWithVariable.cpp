/* Take two numbers and swap their values with a third variables */

#include <iostream>

int main()
{
    // Variables whose contents are to be swapped
    int x;
    int y;

    // Take user input
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    std::cout << "Enter a value for y: ";
    std::cin >> y;

    // Swapping is an elementary operation in many sorting algorithms
    int temp = x;
    x = y;
    y = temp;

    // Print the results
    std::cout << "After swapping: " << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}
