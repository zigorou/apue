#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>

#include "error.h"

int main(int argc, char **argv) {
    int            i;
    struct stat    statbuf;
    struct utimbuf timebuf;

    for (i = 0; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            err_ret("%s: stat error", argv[i]);
            continue;
        }

        if (open(argv[i], O_RDWR|O_TRUNC) < 0) {
            err_ret("%s: open error", argv[i]);
            continue;
        }

        timebuf.actime  = statbuf.st_atime;
        timebuf.modtime = statbuf.st_mtime;

        if (utime(argv[i], &timebuf) < 0) {
            err_ret("%s: utime error", argv[i]);
            continue;
        }
    }

    exit(0);
}
