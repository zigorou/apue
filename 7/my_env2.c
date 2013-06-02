#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **environ) {
    int i;

    for (i = 0; environ[i] != NULL; i++)
        printf("environ[%d]: %s\n", i, environ[i]);

    exit(0);
}
