#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void pr_stdio(const char *name, FILE *fp);

int main(void) {
    FILE *fp;

    fputs("enter any character\n", stdout);
    if (getchar() == EOF)
        err_sys("getchar error");
    fputs("one line to standard error\n", stderr);
    
    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ( ( fp = fopen("/etc/passwd", "r") ) == NULL )
        err_sys("fopen error");
    else if (getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("/etc/passwd", fp);

    exit(0);
}

void pr_stdio(const char *name, FILE *fp) {
    printf("stream = %s, ", name);

    // Only works on MacOSX?
    if (fp->_flags & _IONBF)
        printf("unbuffered");
    else if (fp->_flags & _IOLBF)
        printf("line buffered");
    else
        printf("fully buffered");

    printf(", buffer size = %d\n", fp->_blksize);
}
