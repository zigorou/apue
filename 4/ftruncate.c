#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "error.h"

#define MAXLENGTH 4098

int main(int argc, char **argv) {
    int fd, n;
    char *filepath, buf[MAXLENGTH];
    off_t orig_file_length, truncate_length;
    struct stat stat_buf;
    
    if (argc != 3) {
        err_quit("usage: %s filename truncate_length", argv[0]);
    }

    filepath = argv[1];
    truncate_length = (off_t) atoi(argv[2]);
    
    if (( fd = open(filepath, O_RDWR) ) < 0) {
        err_sys("open error for %s", filepath);
    }

    if (fstat(fd, &stat_buf) < 0) {
        err_sys("fstat error");
    }

    printf("filesize: %d. truncate size: %d.\n", (int) stat_buf.st_size, (int) truncate_length);

    orig_file_length = stat_buf.st_size;

    if (ftruncate(fd, truncate_length) < 0) {
        err_sys("ftruncate error");
    }

    if (orig_file_length > truncate_length) {
        if (lseek(fd, truncate_length, SEEK_SET) < 0) {
            err_sys("lseek error");
        }

        if ((n = read(fd, buf, (size_t) (orig_file_length - truncate_length))) < 0) {
            err_ret("read error");
        }
        else {
            printf("%s (read buffer: %d bytes)\n", buf, n);
        }
    }
    else {
        if (lseek(fd, orig_file_length, SEEK_SET) < 0) {
            err_sys("lseek error");
        }

        if ((n = read(fd, buf, (size_t) (truncate_length - orig_file_length))) < 0) {
            err_ret("read error");
        }
        else {
            printf("%s (read buffer: %d bytes)\n", buf, n);
        }
    }

    close(fd);

    exit(0);
}
