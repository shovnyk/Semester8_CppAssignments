/* 
   Take an array of n integers.
   Sort it into ascending order using bubble sort.
   Now take another integer element m and search whether it is present in the array.
   Use binary search method.
   n and m will be given as input from the user.
*/

#include <iostream>

using namespace std;

// Perform bubblesort on the contents of an array
void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Perform binary search on a sorted array and return index at which found
int binarySearch(int arr[], int len, int key)
{
    int low = 0;
    int high = len-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (key < arr[mid]) {
            high = mid - 1;
        }
        if (key > arr[mid]) {
            low = mid + 1;
        }
        if (key == arr[mid]) {
            cout << mid << endl;
            return mid;
        }
    }
    return -1;
}

int main()
{
    // Take array as input
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the contents of the array
    bubbleSort(arr, n);
    cout << "Sorted array = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Search for an element in the array
    int m;
    cout << "Enter an element to search for in the array: ";
    cin >> m;
    int index = binarySearch(arr, n, m);
    if (index == -1) {
        cerr << "Element not found in array." << endl;
    }
    else {
        cout << "Element found at index = " << index << endl;
    }

    // Free array allocated allocated by new []
    delete[] arr;
}
