#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "unlink_config.h"

int main(void) {
    if (open("tempfile", O_RDWR|O_CREAT) < 0)
        err_sys("open error");

    if (unlink("tempfile") < 0)
        err_sys("unlink error");

    printf("### file unlinked\n");

#ifdef UNLINK_DEBUG
    system("ls -l tempfile");
    system("df .");
#else
    sleep(UNLINK_SLEEP);
#endif

    printf("### done\n");

    exit(0);
}


