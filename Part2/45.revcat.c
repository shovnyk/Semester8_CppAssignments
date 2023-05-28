/* Reverse and concatenate strings using plain C. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *revcat(const char *s1, const char *s2)
{
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    char *buff = malloc(s1len + s2len);
    for (int i = s2len - 1; i >= 0; i--) {
        *buff++ = s2[i];
    }
    for (int i = s1len - 1; i >= 0; i--) {
        *buff++ = s1[i];
    }
    buff -= (s1len + s2len);
    return buff;
}

char rstrip(char *buff)
{
    while (*buff++ != '\n');
    *--buff = 0;
}

int main()
{
    char string1[256];
    char string2[256];

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);

    rstrip(string1);
    rstrip(string2);

    char *result = revcat(string1, string2);
    printf("Result = %s\n", result);

    free(result);
    return 0;
}
