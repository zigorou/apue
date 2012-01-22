#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"

#define FILE_MODE 0644

static const char buf1[] = "abcdefghij";
static const char buf2[] = "ABCDEFGHIJ";

/*
 * od -tx1c file.hole
 */
int main(void) {
    int fd;

    if ( ( fd = creat("file.hole", FILE_MODE) ) < 0 )
        err_sys("creat error");

    if ( write(fd, buf1, 10) != 10 )
        err_sys("buf1 write error");

    if ( lseek(fd, 40, SEEK_SET) == -1 )
        err_sys("lseek error");

    if ( write(fd, buf2, 10) != 10 )
        err_sys("buf2 write error");

    close(fd);

    exit(0);
}
