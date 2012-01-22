#include <stdio.h>
#include <stdlib.h>

#include "open_max.h"
#include "path_alloc.h"

int main(void) {
    int  path_max_size, open_max_size;
    char *ptr;
    
    ptr = path_alloc(&path_max_size);
    printf("PATH_MAX = %d\n", path_max_size);
    free(ptr);

    open_max_size = open_max();
    printf("OPEN_MAX = %d\n", open_max_size);

    exit(0);
}
