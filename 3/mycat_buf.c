#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/types.h>

#include "error.h"

static int clocks_per_second;

void rw(int read_fd, int buffsize) {
    int         l, n, user, sys;
    char       *buf;
    struct tms  ts1, ts2;

    buf      = malloc(sizeof(char) * buffsize);
    if (buf == NULL)
        err_sys("malloc error");

    lseek(read_fd, 0, SEEK_SET);
    
    l = 0;

    times(&ts1);
    while ( ( n = read(read_fd, buf, buffsize) ) > 0 ) {
        if ( write(STDERR_FILENO, buf, n) != n )
            err_sys("write error");
        l++;
    }
    times(&ts2);

    free(buf);
    
    user = (int) ( ts2.tms_utime - ts1.tms_utime );
    sys  = (int) ( ts2.tms_stime - ts1.tms_stime );

    printf("%d,%.1f,%.1f,%.1f,%d\n", 
        buffsize,
        (double) (user / clocks_per_second), 
        (double) ( sys / clocks_per_second ), 
        (double) ( (user + sys) / clocks_per_second ),
        l);
    return;
}

int main(int argc, char **argv) {
    int         i, buffsize, fd;

    if (argc != 2)
        err_quit("usage: %s <file>", argv[0]);

    clocks_per_second = (int) sysconf(_SC_CLK_TCK);

    if ( ( fd = open(argv[1], O_RDONLY) ) < 0 )
        err_sys("open error");

    for (i = 0; i <= 17; i++) {
        buffsize = 1 << i;
        rw(fd, buffsize);
    }

    close(fd);

    exit(0);
}
