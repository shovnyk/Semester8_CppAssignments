/* Take 2 matrices from the user. 
   Then multiply these 2 matrices.
   Print the result. */

#include <iostream>

using namespace std;

int* matrixProduct(int* matrixA, int nrowsA, int ncolsA,
                   int* matrixB, int nrowsB, int ncolsB) {  // O(N^3)
    // Check if compatible for multiplication
    if (ncolsA != nrowsB)
        return nullptr;

    int commonDimension = ncolsA; // Same as nrowsB
    int nrowsProduct = nrowsA;
    int ncolsProduct = ncolsB;
    int* product = new int[nrowsProduct * ncolsProduct]; // Must be deallocated in caller

    for (int i = 0; i < nrowsProduct; i++) {
        for (int j = 0; j < ncolsProduct; j++) {
            int sum = 0;
            for (int k = 0; k < commonDimension; k++) {
                sum += matrixA[i*ncolsA + k]*matrixB[k*ncolsB + j];
            }
            product[i*ncolsProduct + j] = sum;
        }
    }

    return product;
}

void input(int* matrix, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++) {
        cout << "Enter elements of row " << i << ": ";
        for (int j = 0; j < ncols; j++) {
            cin >> matrix[i*ncols + j];
        }
    }
}

void print(int* matrix, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            cout << matrix[i*ncols + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int nrowsA, ncolsA;
    cout << "Enter dimensions of first matrix: ";
    cin >> nrowsA >> ncolsA;
    int* A = new int[nrowsA*ncolsA]; 
    input(A, nrowsA, ncolsA);

    int nrowsB, ncolsB;
    cout << "Enter dimensions of second matrix: ";
    cin >> nrowsB >> ncolsB;
    int* B = new int[nrowsB*ncolsB];
    input(B, nrowsB, ncolsB);

    int* C = matrixProduct(A, nrowsA, ncolsA, B, nrowsB, ncolsB);
    if (C == nullptr) {
        cerr << "Matrices not compatible for multiplication." << endl;
        return 1;
    }

    cout << "Matrix product: " << endl;
    print(C, nrowsA, ncolsB);

    delete[] A;
    delete[] B;
    delete[] C;
}
