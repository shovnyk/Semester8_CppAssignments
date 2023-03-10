/* Take 3x3 matrix as input from user and check if it is a diagonal matrix. */

#include <iostream>

using namespace std;

bool isDiagonal(int* matrix, int order)
{
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if ((i != j) && (matrix[i*order + j] != 0))
                return false;
        }
    }
    return true;
}

int main()
{
    int order = 3;
    int* matrix = new int[order*order];
    cout << "Enter the elements of a 3x3 matrix." << endl;
    for (int i = 0; i < order; i++) {
        cout << "Enter elements of row " << i << ": ";
        for (int j = 0; j < order; j++) {
            cin >> matrix[i*order + j];
        }
    }
    cout << "Matrix"  << (isDiagonal(matrix, order)? " is " : " isnt ");
    cout << "a diagonal matrix." << endl;
    delete[] matrix;
}
