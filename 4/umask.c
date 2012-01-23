#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "error.h"

int main(int argc, char **argv) {
    umask(0);

    if (creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
        err_sys("creat erro for foo");

    umask(S_IRGRP | S_IROTH | S_IWOTH);

    if (creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
        err_sys("creat erro for bar");

    exit(0);
}
