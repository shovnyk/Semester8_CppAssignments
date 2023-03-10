/* Take 2 strings from user and implement the functionality of strcmp() function
   on them by your own logic (in C). */

#include <stdio.h>
#include <string.h> /* strcmp() for reference. */
       
int mystrcmp(const char *s1, const char *s2) /* Constant char pointer, pointer itself is mutable. */
{
    do {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    } while (*s1 != 0 && *s2 != 0);
    return *s1 - *s2;
}

void rstrip(char *s)
{
    while (*s++ != '\n');
    *--s = 0;
}

int main()
{
    char string1[256] = {0};
    char string2[256] = {0};
    printf("Enter first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter second string: "); 
    fgets(string2, sizeof(string2), stdin);

    rstrip(string1);
    rstrip(string2);

    int x = mystrcmp(string1, string2);
    if (x == 0) {
        printf("%s = %s\n", string1, string2);
    }
    else if (x < 0) {
        printf("%s < %s\n", string1, string2);
    }
    else {
        printf("%s > %s\n", string1, string2);
    }
    return 0;
}
