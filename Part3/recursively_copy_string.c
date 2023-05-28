/* Recursively copy the contents of one string into another */
#include <stdio.h>

void strcpyrec(char *dest, const char *src)
{
    
    *dest = *src;
    if (*src == 0) {
        return;
    }
    strcpyrec(dest + 1, src + 1);
}

int main()
{
    char s[] = "foobar";
    char d[100] = {0};
    printf("Initially, d = '%s'\n", d);
    strcpyrec(d, s);
    printf("After copying, d = '%s'\n", d);
}
