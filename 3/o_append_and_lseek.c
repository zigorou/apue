#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "error.h"

#define BUFFSIZE 8192

char *str_whence(int whence) {
    char *str;
    switch (whence) {
        case SEEK_SET:
            str = "SEEK_SET";
            break;
        case SEEK_CUR:
            str = "SEEK_CUR";
            break;
        case SEEK_END:
            str = "SEEK_END";
            break;
        default:
            str = "UNKNONW";
            break;
    }

    return str;
}

int main(int argc, char **argv) {
    int ch, whence, n, is_read, is_write;
    int fd;
    size_t offset;
    char buf[BUFFSIZE];

    n      = 0;
    offset = 0;
    whence = SEEK_CUR;

    while ((ch = getopt(argc, argv, "o:w:R:W:")) != -1) {
        switch (ch) {
            case 'o':
                offset = (size_t) atoi(optarg);
                break;
            case 'w':
                if (strcmp(optarg, "SEEK_SET") == 0) {
                    whence = SEEK_SET;
                }
                else if (strcmp(optarg, "SEEK_CUR") == 0) {
                    whence = SEEK_CUR;
                }
                else if (strcmp(optarg, "SEEK_END") == 0) {
                    whence = SEEK_END;
                }
                else
                    err_quit("unknown whence (%s)", optarg);
                break;
            case 'R':
                if (!is_write) {
                    n = atoi(optarg);
                    is_read = 1;
                }
                break;
            case 'W':
                if (!is_read) {
                    strncpy(buf, optarg, BUFFSIZE);
                    n = strlen(buf) + 1;
                    is_write = 1;
                }
                break;
            case '?':
            default:
                break;
        }
    }

    argc -= optind;

    if (argc != 1)
        err_quit("usage: %s [options] <file>", argv[0]);

    argv += optind;

    if ((fd = open(argv[0], O_RDWR|O_APPEND|O_CREAT)) == -1)
        err_sys("open error for %s", argv[0]);

    if (lseek(fd, offset, whence) == -1)
        err_sys("lseek error for %d, %s", (int) offset, str_whence(whence));
    else
        printf("lseek (offset: %d, whence: %s)\n", (int) offset, str_whence(whence));

    if (is_read) {
        if (read(fd, buf, n) < 0)
            err_sys("read error");

        printf("read: %s\n", buf);
    }
    else if (is_write) {
        if (write(fd, buf, n) != n)
            err_sys("write error");
    }

    close(fd);

    exit(0);
}
