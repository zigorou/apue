#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "error.h"
#define MAX_STRFTIME_BUF 1024

int main(int argc, char **argv) {
    time_t cal;
    struct tm *t;
    char buf[MAX_STRFTIME_BUF];

    if (time(&cal) != (time_t) -1) {
        if ( (t = localtime(&cal) ) != NULL ) {
            if ( strftime(buf, (size_t) MAX_STRFTIME_BUF, "%a %b %d %H:%M:%S %Z %Y", t) != 0) {
                printf("%s\n", buf);
            }
        }
        else {
            err_sys("localtime(3) error");
        }
    }
    else {
        err_sys("time(3) error");
    }

    exit(0);
}
