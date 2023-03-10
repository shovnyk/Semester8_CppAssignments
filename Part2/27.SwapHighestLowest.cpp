/* 
    Take an array of 20 integers. 
    Pass the array to a function swap(). 
    It will swap the lowest and highest element in the array and return to main.
*/

#include <iostream>
#include <climits>

int* swapLowestAndHighest(int* arr, int len)
{ 
    int min, max;
    min = INT_MAX;
    max = INT_MIN;
    int minindex, maxindex;
    for (int i = 0; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minindex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxindex = i;
        }
    }
    // swap contents
    int temp = arr[minindex];
    arr[minindex] = arr[maxindex];
    arr[maxindex] = temp;
    return arr;
}

int main()
{
    int arr[20];
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Enter 20 elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    int* narr = swapLowestAndHighest(arr, len);

    printf("Array after swapping: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", narr[i]);
    }
    printf("\n");
}
