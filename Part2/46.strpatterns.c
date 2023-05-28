/* Print string patterns. */

#include <stdio.h>

void pattern1()
{
    char word[] = "COMPUTER"; /* bytes "COMPUTER" + NULL byte */
    int wordlen = sizeof(word) - 1; /* total number of bytes - 1 null byte */
    for (int j = wordlen - 1; j >= 0; j--) {
        for (int k = 0; k <= j; k++) {
            putchar(word[k]);
        }
        putchar('\n');
    }
}

void pattern2()
{
    char word[] = "COMPUTER";
    int wordlen = sizeof(word) - 1;
    for (int i = 0; i < wordlen; i++) {
        for (int j = 0; j < wordlen; j++) {
            if (j >= i) {
                putchar(word[j]);
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void pattern3()
{
    char word[] = "HELLO";
    int wordlen = sizeof(word) - 1;
    for (int i = 0; i < wordlen; i++) {
        for (int j = 0; j <= i; j++) {
            putchar(word[j]);
        }
        putchar('\n');
    }
    for (int i = wordlen - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            putchar(word[j]);
        }
        putchar('\n');
    }
}

void pattern4()
{
    char word[] = "COMPUTER";
    int wordlen = sizeof(word) - 1;
    for (int i = 0; i < wordlen; i++) {
        int k = 0;
        for (int j = 0; j < wordlen; j++) {
            if (j >= i) {
                putchar(word[k++]);
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main()
{
    pattern1();
    pattern2();
    pattern3();
    pattern4();
    return 0;
}
