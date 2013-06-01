#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "error.h"

int main(int argc, char **argv) {
    if (argc != 2)
        err_quit("usage: %s <name>", argv[0]);

    struct passwd *ptr;

    if ( (ptr = getpwnam(argv[1])) != NULL ) {
        printf(
            "uid=%d(%s) pw_passwd=%s\n",
            ptr->pw_uid,
            ptr->pw_name,
            ptr->pw_passwd
        );
    }
    else {
        err_quit("id: %s: no such user", argv[1]);
    }

    exit(0);
}
