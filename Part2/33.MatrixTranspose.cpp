/* 
    Take an m x n matrix as input from user.
    Then print the transpose of the matrix.
    The idea is to take a single dimensional array and treat it as a
    2-dimensional array by treating element at index (x, y) of an equivalent 2D
    array as that at index x*width + y of the 1D array. where width is the
    number of columns of the matrix.
*/

#include <iostream>

using namespace std;

void input(int* matrix, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++) {
        cout << "Enter " << nrows << " elements of row " << i << ": ";
        for (int j = 0; j < ncols; j++) {
            cin >> matrix[i*ncols + j];
        }
    }
}

void display(int* matrix, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            cout << matrix[i*ncols + j] << " ";
        }
        cout << endl;
    }
}

int* transpose(int* matrix, int nrows, int ncols)
{
    int* matrixTransposed = new int[nrows*ncols]; // Must be deallocated in caller
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            matrixTransposed[j*nrows + i] = matrix[i*ncols + j];
        }
    }
    return matrixTransposed;
}

int main()
{
    int m, n; // m = #rows, n = #cols
    cout << "Enter the order of the matrix: ";
    cin >> m >> n;

    // Allocate a single 1D array dynamically on the heap
    int* matrix = new int[m * n];

    // Take in elements of the array from the user
    input(matrix, m, n);

    // Print the contents before transpose
    cout << "Matrix you entered: " << endl;
    display(matrix, m, n);

    // Tranpose contents of matrix (interchange rows and columns)
    int* matrixTransposed = transpose(matrix, m, n);

    // Print the contents after transpose
    cout << "After tranpose: " << endl;
    display(matrixTransposed, n, m);

    // Deallocate matrices and exit
    delete[] matrix;
    delete[] matrixTransposed;
}
