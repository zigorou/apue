#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "path_alloc.h"

int main(int argc, char **argv) {
    char *actualpath, *sympath, *path_buf;
    int buf_size;

    if (argc != 3) {
        err_quit("usage: %s <actualpath> <sympath>", argv[0]);
    }

    actualpath = argv[1];
    sympath    = argv[2];

    if (symlink(actualpath, sympath) < 0) {
        err_sys("symlink error for %s to %s", actualpath, sympath);
    }

    path_buf = path_alloc(&buf_size);

    if (readlink(sympath, path_buf, buf_size) < 0) {
        err_sys("readlink error for %s", sympath);
    }

    printf("%s -> %s\n", sympath, path_buf);
    exit(0);
}
