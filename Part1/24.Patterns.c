/* Print the following by writing separate C programs */

#include <stdio.h>

void pattern1(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--)
            printf("%d", j);
        printf("\n");
    }
}

void pattern2(int n)
{
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            printf("%d", i);
        printf("\n");
    }
}

void pattern3(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i)
                putchar('*');
            else
                putchar(' ');
        }
        printf("\n");
    }
}

void pattern4(int h)
{
    int w = 2*h - 1;
    int mid = w/2;
    for (int i = 0; i < h; i++) {
        int k = 0;
        for (int j = 0; j < w; j++) {
            if ((j >= mid - i) && (j <= mid + i)) {
                if ((j >= mid - i) && (j <= mid)) {
                    printf("%d", ++k);
                }
                if ((j > mid) && (j <= mid + i)) {
                    printf("%d", --k);
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void pattern5(int h)
{
    int w = 2*h - 1;
    int mid = w/2;
    for (int i = mid; i >= 0; i--) {
        int k = 0;
        for (int j = 0; j < w; j++) {
            if ((j >= mid - i) && (j <= mid + i)) {
                printf("%d", (++k) % 2);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    pattern1(5); printf("\n");
    pattern2(5); printf("\n");
    pattern3(5); printf("\n");
    pattern4(5); printf("\n");
    pattern5(5); printf("\n");
    return 0;
}
