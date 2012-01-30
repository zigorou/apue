#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "error.h"
#include "path_alloc.h"

#define FTW_F   1
#define FTW_D   2
#define FTW_DNR 3
#define FTW_NS  4

typedef int Myfunc(const char *, const struct stat *, int);
static Myfunc myfunc;
static int myftw(char *, Myfunc *);
static int dopath(Myfunc *);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
static char *fullpath;

int main(int argc, char **argv) {
    int ret;

    if (argc != 2)
        err_quit("usage: %s <starting-pathname>", argv[0]);

    ret = myftw(argv[1], myfunc);

    if ( ( ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock ) == 0 )
        ntot = 1;

    printf("regular files  = %7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
    printf("directories    = %7ld, %5.2f %%\n", ndir, ndir * 100.0 / ntot);
    printf("block special  = %7ld, %5.2f %%\n", nblk, nblk * 100.0 / ntot);
    printf("char special   = %7ld, %5.2f %%\n", nchr, nchr * 100.0 / ntot);
    printf("FIFOs          = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0 / ntot);
    printf("symbolic links = %7ld, %5.2f %%\n", nslink, nslink * 100.0 / ntot);
    printf("sockets        = %7ld, %5.2f %%\n", nsock, nsock * 100.0 / ntot);

    exit(ret);
}

static int myftw(char *pathname, Myfunc *func) {
    fullpath = path_alloc(NULL);
    strcpy(fullpath, pathname);
    return(dopath(func));
}

static int dopath(Myfunc *func) {
    struct stat    statbuf;
    struct dirent *dirp;
    DIR           *dp;
    int            ret;
    char          *ptr;

    if (lstat(fullpath, &statbuf) < 0)
        return(func(fullpath, &statbuf, FTW_NS));

    if (S_ISDIR(statbuf.st_mode) == 0)
        return(func(fullpath, &statbuf, FTW_F));

    if ( ( ret = func(fullpath, &statbuf, FTW_D)) != 0 )
        return(ret);

    ptr = fullpath + strlen(fullpath);
    *ptr++ = '/';
    *ptr = 0;

    if ( ( dp = opendir(fullpath) ) == NULL )
        return(func(fullpath, &statbuf, FTW_DNR));

    while ( (dirp = readdir(dp)) != NULL ) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;

        strcpy(ptr, dirp->d_name);

        if ( (ret = dopath(func) ) != 0 )
            break;
    }

    ptr[-1] = 0;

    if (closedir(dp) < 0)
        err_ret("can't close directory %s", fullpath);

    return(ret);
}

static int myfunc(const char *pathname, const struct stat *statptr, int type) {
    switch (type) {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT) {
                case S_IFREG:
                    nreg++; break;
                case S_IFBLK:
                    nblk++; break;
                case S_IFCHR:
                    nchr++; break;
                case S_IFIFO:
                    nfifo++; break;
                case S_IFLNK:
                    nslink++; break;
                case S_IFSOCK:
                    nsock++; break;
                case S_IFDIR:
                    err_dump("for S_IFDIR for %s", pathname);
            }
            break;
        case FTW_D:
            ndir++;
            break;
        case FTW_DNR:
            err_ret("can't read directory %s", pathname);
            break;
        case FTW_NS:
            err_ret("stat error for %s", pathname);
            break;
        default:
            err_dump("unknown type %d for pathname %s", type, pathname);
    }

    return(0);
}
