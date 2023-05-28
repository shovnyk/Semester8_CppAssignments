/* 
   Take length and breadth of a rectangular wire as input from user. 
   Print its area and perimeter.
   Now the same wire is bent to form a circle. 
   Calculate the radius of the circle.
*/

#include <iostream>

using namespace std;

const float pi = 3.1415F; // prefer const variables to #defines for constants

int main()
{
    int length, breadth;
    int area, perimeter;
    float radius;

    cout << "Enter the length of the rectangle (units): ";
    cin >> length;
    cout << "Enter the breadth of the rectangle (units): ";
    cin >> breadth;

    area = length * breadth;
    perimeter = 2*(length + breadth);

    cout << "Area of the rectangle: " << area << " units-squared." << endl;
    cout << "Perimeter of the rectangle: " << perimeter << " units." << endl;

    /* The circumference of the circle will be the same as the perimeter of the square */
    radius = (length + breadth)/pi;

    cout << "Radius of the circle: " << radius << " units." << endl;
}
