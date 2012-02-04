#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"

int main(void) {
    if ( chdir("/tmp") < 0 )
        err_sys("chdir failed");

    printf("chdir to /tmp succeeded\n");
    exit(0);
}
