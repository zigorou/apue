#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "error.h"

int main(int argc, char **argv) {
    int n, buffsize;
    char *buf;

    if (argc != 2)
        err_quit("usage: %s <buffsize>", argv[0]);

    buffsize = atoi(argv[1]);
    buf = calloc(buffsize, sizeof(char));
    if ( buf == NULL )
        err_sys("calloc error");

    while ( ( n = read(STDIN_FILENO, buf, buffsize) ) > 0 ) {
        if ( write(STDOUT_FILENO, buf, n) != n )
            err_sys("write error");
    }

    if ( n < 0 )
        err_sys("read error");

    exit(0);
}
