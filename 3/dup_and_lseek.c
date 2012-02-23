#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "error.h"
#include "path_alloc.h"

void setpos_and_show(int fd, size_t offset, int whence);

int main(int argc, char **argv) {
    int is_append, flags, ch, fd1, fd2;
    off_t offset;
    char *filename;

    is_append = 0;
    filename = path_alloc(NULL);
    
    while ((ch = getopt(argc, argv, "af:")) != -1) {
        switch (ch) {
            case 'a':
                is_append = 1;
                break;
            case 'f':
                strcpy(filename, optarg);
                break;
            case '?':
            default:
                err_quit("usage: %s [-a] [-f file]", argv[0]);
        }
    }

    argc -= optind;
    argv += optind;

    if (strlen(filename) > 0) {
        flags = O_CREAT | O_RDWR;
        if (is_append)
            flags |= O_APPEND;

        if ( (fd1 = open(filename, flags)) < 0)
            err_sys("open error for %s", filename);
    }
    else 
        fd1 = STDIN_FILENO;

    if ((fd2 = dup(fd1)) == -1)
        err_sys("dup error");

    setpos_and_show(fd1, 0, SEEK_END);
    setpos_and_show(fd2, 0, SEEK_END);

    if (write(fd1, "abcde", 5) != 5)
        err_sys("write error for fd1");

    setpos_and_show(fd1, 0, SEEK_CUR);
    setpos_and_show(fd2, 0, SEEK_CUR);

    if (write(fd2, "abcde", 5) != 5)
        err_sys("write error for fd2");

    setpos_and_show(fd1, 0, SEEK_CUR);
    setpos_and_show(fd2, 0, SEEK_CUR);

    free(filename);

    exit(0);
}

void setpos_and_show(int fd, size_t offset, int whence) {
    size_t got_offset;

    if ((got_offset = lseek(fd, offset, whence)) == -1)
        err_sys("lseek error for %d", fd);

    printf("%d offset: %d\n", fd, (int) got_offset);
}
