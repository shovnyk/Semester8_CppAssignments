/* 
   C program to read contents of a file and print all even numbers. 
   The file is is assumed to be a plain text file in utf-8 encoding containing
   a number on each new line. To generate a sequence of numbers from the 
   Linux command line, and then store them in a file, do:
    
   $ seq 1 100 >numbers.txt
*/

#include <stdio.h>

#define LINE_LENGTH BUFSIZ

int main(int argc, char *argv[])
{
    /* Read in arguments from the command line. Report and exit if not provided. */
    if (argc < 2) {
        fprintf(stderr, "Expected file name as positional argument to program.\n");
        return 1;
    }
    char *filename = argv[1];

    /* Try to open a file in "r" mode. Report an error and exit on failure. */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }

    /* Declare a buffer large enough to store lines from the file to be read. */
    char linebuffer[LINE_LENGTH];

    /* Fetch lines from the file into the buffer until there aren't anymore to fetch.
       Fetching entire lines and then extracting data from the line is more efficient
       compared to fetching individual bytes which will require more function calls. */
    while (fgets(linebuffer, LINE_LENGTH, fp) != NULL) {
        int number;
        sscanf(linebuffer, "%d\n", &number); /* Convert to number. */
        if ((number & 1) == 0)               /* Check if even. */
            printf("%d\n", number);          /* Print if even. */
    }

    return 0;
}
