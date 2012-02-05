#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "error.h";

#define BUFFSIZE 8192

int main(int argc, char **argv) {
    int         read_fd, write_fd, n;
    char        buf[BUFFSIZE];
    struct stat statbuf;

    if (argc != 3)
        err_quit("usage: %s <source_file> <target_file>", argv[0]);

    if ( ( read_fd = open(argv[1], O_RDONLY) ) < 0 )
        err_sys("open error for %s", argv[1]);

    if ( fstat(read_fd, &statbuf) < 0 )
        err_sys("fstat error for %s", argv[1]);

    if ( ( write_fd = open(argv[2], O_WRONLY|O_CREAT, statbuf.st_mode & (S_IRWXU|S_IRWXG|S_IRWXO)) ) < 0 )
        err_sys("open error for %s", argv[2]);

    while ( ( n = read(read_fd, buf, BUFFSIZE) ) > 0 ) {
        if ( write(write_fd, buf, n) != n )
            err_sys("write error for %s", argv[2]);
    }

    if ( n < 0 )
        err_sys("read error for %s", argv[1]);

    exit(0);
}
