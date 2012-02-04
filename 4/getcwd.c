#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "path_alloc.h"

int main(void) {
    char *ptr;
    int  size;

    if (chdir("/var/tmp") < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
    exit(0);
}
