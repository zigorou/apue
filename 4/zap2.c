#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>

#include "error.h"

int main(int argc, char **argv) {
    int            i;
    struct stat    statbuf;
    struct timeval tv[2];

    for (i = 0; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            err_ret("%s: stat error", argv[i]);
            continue;
        }

        if (open(argv[i], O_RDWR|O_TRUNC) < 0) {
            err_ret("%s: open error", argv[i]);
            continue;
        }

        tv[0].tv_sec = statbuf.st_atime;
        tv[1].tv_sec = statbuf.st_mtime;

        if (utimes(argv[i], tv) < 0) {
            err_ret("%s: utime error", argv[i]);
            continue;
        }
    }

    exit(0);
}
