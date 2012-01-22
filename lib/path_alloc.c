#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "path_alloc.h"

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

char *path_alloc(int *size) {
    char *ptr;

    if (pathmax == 0) {
        errno = 0;
        if ( ( pathmax = pathconf("/", _PC_PATH_MAX) ) < 0 ) {
            if ( errno == 0 )
                pathmax = PATH_MAX_GUESS;
            else
                err_sys("pathconf error for _PC_PATH_MAX");
        }
        else
            pathmax++;
    }

    if ( ( ptr = malloc(pathmax + 1) ) == NULL )
        err_sys("malloc error for pathname");

    if ( size != NULL )
        *size = pathmax + 1;

    return(ptr);
}
