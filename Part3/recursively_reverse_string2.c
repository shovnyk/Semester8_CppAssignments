#include <stdio.h>
#include <string.h>

void strrevrec(char *dest, const char *src, int len)
{
    *dest = src[len - 1];
    if (len == 1)
        return;
    strrevrec(dest + 1, src, len - 1);
}

int main()
{
    char s[] = "helloworld";
    printf("Original string = %s\n", s);
    char d[sizeof(s)] = {0};
    strrevrec(d, s, strlen(s));
    printf("Reversed string = %s\n", d);
    return 0;
}
