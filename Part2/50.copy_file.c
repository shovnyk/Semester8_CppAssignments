/* Open a file in “r” mode. 
   Then copy the contents of this file into another file. 
   The file name(s) will be taken in as command line arguments. */

#include <stdio.h>

#define LINE_LENGTH BUFSIZ

int main(int argc, char *argv[])
{
    char *prgname = argv[0];
    if (argc < 3) {
        fprintf(stderr, "File(s) not provided.\n");
        fprintf(stderr, "Usage: %s <SOURCE> <DESTINATION>\n", prgname);
        return 1;
    }

    char *srcname = argv[1];
    char *destname = argv[2];
    FILE *src = fopen(srcname, "r");
    FILE *dest = fopen(destname, "w");

    if (src == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", srcname);
        return 2;
    }
    if (dest == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", destname);
        return 3;
    }

    char linebuffer[LINE_LENGTH] = {0};
    while (fgets(linebuffer, LINE_LENGTH, src) != NULL) /* Fetch line from source file */
    {
        /* Write it to destination file. 
           fputs() preferred because is being called multiple times in a loop 
           and we do not need to do any formatting on the buffer before it is
           written. */
        fputs(linebuffer, dest);
    }

    /* Clean up and exit */
    fclose(src);
    fclose(dest);
    return 0;
}

/* 
   Compiling, running and demonstration:
    $ gcc -Wall -std=c99 -Wpedantic 50.copy_file.c
    $ ./a.out source.txt destination.txt
    $ diff source.txt destination.txt
*/
