/* 
   Implement your own versions of the C standard library's string manipulation
   functions. 
*/

#include <stdio.h>

const char nullterminator = 0x00;

void mystrcpy(char *dest, const char *src)
{
    while (*src != nullterminator)
        *dest++ = *src++;
    *dest = nullterminator;
}

int mystrlen(const char *s)
{
    int i;
    for (i = 0; s[i] != nullterminator; ++i);
    return i;
}

void mystrrev(char *dest, const char *src)
{
    for (int i = mystrlen(src) - 1; i >= 0; i--)
        *dest++ = src[i];
    *dest = nullterminator;
}

void mystrcat(char *dest, const char *src)
{
    char *destend = dest + mystrlen(dest);
    while (*src != nullterminator)
        *destend++ = *src++;
    *destend = nullterminator;
}

int main(void)
{
    char s[] = "HelloWorld";
    char d[sizeof(s)] = {0}; // fixed sized array because sizeof is a compile time operator
    printf("'%s' has %d characters in it.\n", s, mystrlen(s));
    
    printf("Originally, d = '%s'\n", d);
    mystrcpy(d, s);
    printf("After copying, d = '%s'\n", d);
    
    mystrrev(d, s);
    printf("After reversing, d = '%s'\n", d);
    
    char e[100] = "FooBar"; // reserve enough space for concatenation
    printf("Before concatenation, e = '%s'\n", e);
    mystrcat(e, s);
    printf("After concatenation, e = '%s'\n", e);
    
    return 0;
}
