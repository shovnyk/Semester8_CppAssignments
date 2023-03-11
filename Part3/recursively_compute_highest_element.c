/* Recursively find the max element in an array. */
#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int maxarr(int *arr, int len)
{
    if (len == 1)
        return arr[0];
    return max(arr[0], maxarr(arr + 1, len - 1));
}

int main()
{
    int arr[] = {1, 2, 3, 7, 4, 0};
    int arrlen = sizeof(arr)/sizeof(int);
    int highest = maxarr(arr, arrlen);
    printf("Max element = %d\n", highest);
    return 0;
}
