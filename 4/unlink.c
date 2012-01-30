#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"

int main(void) {
#ifdef DEBUG
    system("ls -l tempfile");
#endif

    if (open("tempfile", O_RDWR|O_CREAT) < 0)
        err_sys("open error");

    if (unlink("tempfile") < 0)
        err_sys("unlink error");

    printf("file unlinked\n");

#ifdef DEBUG
    system("ls -l tempfile");
    system("df ./");
#endif

    sleep(2);
    printf("done\n");

#ifdef DEBUG
    system("df ./");
#endif

    exit(0);
}


