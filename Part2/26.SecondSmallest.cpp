#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arr[10];
    int len = sizeof(arr)/sizeof(int);

    // Take user input into an array
    cout << "Enter 10 elements to store in an array: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    // Find the (smallest and) second smallest element(s) in the array
    int first, second;
    first = second = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < first) { // arr[i] < first < second
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first) {  // first < arr[i] < second
            second = arr[i];
        }
    }

    // Print out second smallest element in the array
    cout << "Second smallest element = " << second << endl;
}
