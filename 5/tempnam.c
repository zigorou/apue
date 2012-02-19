#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"

int main(int argc, char **argv) {
    if (argc != 3)
        err_quit("usage: %s <directory> <prefix>", argv[0]);

    printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL, argv[2][0] != ' ' ? argv[2] : NULL));

    exit(0);
}
