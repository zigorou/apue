#include <stdio.h>
#include <stdlib.h>

#include "error.h"

int main(int argc, char **argv) {
    char *oldpath, *newpath;

    if (argc != 3) {
        err_quit("usage: %s <oldpath> <newpath>", argv[0]);
    }

    oldpath = argv[1];
    newpath = argv[2];

    if (rename(oldpath, newpath) < 0) {
        err_sys("rename(2) error for %s to %s", oldpath, newpath);
    }
    else {
        printf("rename(2) was suceeded\n");
    }

    exit(0);
}

