#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "error.h"
#include "path_alloc.h"

int main(int argc, char **argv) {
    int   size;
    char *fullpath;

    path_alloc(&size);
    printf("pathmax = %d\n", size - 1) ;

    size = (size - 1) * 2;

    fullpath = malloc(sizeof(char) * size);
    if (fullpath == NULL)
        err_sys("malloc error");

    if ( getcwd(fullpath, size) == NULL )
        err_sys("getcwd error");

    for(;;) {
        printf("mkdir ./a\n");
        if ( mkdir("./a", 0755) < 0 )
            err_sys("mkdir error at %s", fullpath);

        printf("chdir ./a\n");
        if ( chdir("./a") < 0 )
            err_sys("chdir error at %s", fullpath);
        
        printf("getcwd\n");
        if ( getcwd(fullpath, size) == NULL )
            err_sys("getcwd error at %s", fullpath);

        printf("%s %d\n", fullpath, strlen(fullpath));
    }

    exit(0);
}
