#include <stdio.h>
#include <stdlib.h>

#include "error.h"

#define BUFFSIZE 8192

int main(void) {
    char buf[BUFFSIZE];

    while ( fgets(buf, BUFFSIZE, stdin) != NULL ) {
        if ( fputs(buf, stdout) == EOF )
            err_sys("output error");
    }

    if (ferror(stdin))
        err_sys("input error");

    exit(0);
}
