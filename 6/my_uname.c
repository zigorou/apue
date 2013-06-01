#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

#include <errno.h>
#include "error.h"

int main(int argc, char **argv) {
    struct utsname u;

    if ( uname(&u) == 0 ) {
        printf(
            "%s %s %s %s %s\n",
            (&u)->sysname,
            (&u)->nodename,
            (&u)->release,
            (&u)->version,
            (&u)->machine
        );
    }
    else {
        err_sys("uname(3) failed");
    }

    exit(0);
}
