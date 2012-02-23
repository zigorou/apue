#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "path_alloc.h"

int main(int argc, char **argv) {
    int fd, size;
    char *fdescfd_filename;

    if (argc != 2) {
        err_quit("usage: %s <fd>", argv[0]);
    }

    fdescfd_filename = path_alloc(&size);
    snprintf(fdescfd_filename, (size_t) size, "/dev/fd/%d", atoi(argv[1]));

    if ((fd = open(fdescfd_filename, O_CREAT|O_RDWR)) < 0) {
        err_sys("open error for %s", fdescfd_filename);
    }

    if ( write(fd, "abcde", 5) != 5 ) {
        err_sys("write error");
    }

    close(fd);

    exit(0);
}
