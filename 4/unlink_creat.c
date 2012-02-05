#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"

#define FILE_MODE 0755

int main(int argc, char **argv) {
    int   fd;
    char *path;

    if (argc != 2) 
        err_quit("usage: %s <path>", argv[0]);

    path = argv[1];

    if ( unlink(path) )
        err_ret("unlink error for %s", path);

    if ((fd = creat(path, FILE_MODE)) < 0)
        err_sys("creat error for %s", path);

    if (write(fd, "test\n", 5) != 5)
        err_sys("write error for %s", path);

    close(fd);

    exit(0);
}
