#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"

int mydup2(int filedes1, int filedes2);

int main(int argc, char **argv) {
    int fd1, fd2, fd3;
    FILE *fp1, *fp2;

    if (argc != 3)
        err_quit("usage: %s <filedes> <filedes2>", argv[0]);

    fd1 = atoi(argv[1]);
    fd2 = atoi(argv[2]);

    mydup2(fd1, fd2);

    if ( ( fp1 = fdopen(fd1, "w") ) == NULL )
        err_sys("fdopen for %d error", fd1);

    if ( ( fp2 = fdopen(fd2, "w") ) == NULL )
        err_sys("fdopen for %d error", fd2);

    fprintf(fp1, "hello to %d\n", fd1);
    fprintf(fp2, "hello to %d\n", fd2);

    if ( ( fd3 = dup(fd1) ) == -1 )
        err_sys("dup error");

    printf("got fd by dup is %d\n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);

    exit(0);
}

int mydup2(int filedes1, int filedes2) {
    long open_max;
    int i, j, fd, *fds;

    if ( filedes1 < 0 || filedes2 < 0 ) {
        errno = EBADF;
        return -1;
    }

    if ( ( open_max = sysconf(_SC_OPEN_MAX) ) == -1 )
        err_sys("sysconf error");
    
    if ( open_max < filedes2 ) {
        errno = EBADF;
        return -1;
    }

    if ( ( fds = calloc(sizeof(int), (size_t) open_max) ) == NULL )
        err_sys("calloc error");
    
    for (i = 0; i < filedes2; i++) {
        if ( ( fd = dup(filedes1) ) == -1 )
            err_sys("dup error");
        
        if ( fd == filedes2 )
            break;

        fds[i] = fd;
    }

    for (j = 0; j < i; j++) {
        close(fds[j]);
    }

    return fd;
}
