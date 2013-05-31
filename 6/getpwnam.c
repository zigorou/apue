#include <pwd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "error.h"

struct passwd *my_getpwnam(const char *name) {
    struct passwd *ptr;

    setpwent();
    while ( (ptr = getpwent()) != NULL ) {
        if (strcmp(name, ptr->pw_name) == 0)
            break;
    }
    endpwent();
    return ptr;
}

int main(int argc, char **argv) {
    if (argc != 2) 
        err_quit("usage: %s <name>", argv[0]);

    struct passwd *ptr;
    
    if ( (ptr = my_getpwnam(argv[1])) != NULL ) {
        printf(
            "uid=%d(%s) gid=%d\n", 
            ptr->pw_uid, ptr->pw_name,
            ptr->pw_gid
        );
    }
    else {
        err_quit("id: %s: no such user", argv[1]);
    }

    exit(0);
}
