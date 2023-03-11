/* Recursively reverse a string in place */

#include <string.h>
#include <stdio.h>

void swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void strrevrec(char *s, int offset_from_start)
{
    char *start = s;
    char *end = start + offset_from_start;
    swap(start, end);
    if (start == end /* if odd number of characters in original string */
        || start == (end - 1) /* if even number of characters in original string */ )
        return;
    strrevrec(start + 1, offset_from_start - 2);
}

int main()
{
    char s[] = "helloworld"; // includes null byte
    printf("Original string = %s\n", s);
    strrevrec(s, strlen(s) - 1); // modify (reverse) in place
    printf("Reversed string = %s\n", s);
    return 0;
}
