#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv) {
    int i;

    for (i = 0; environ[i] != NULL; i++)
        printf("environ[%d]: %s\n", i, environ[i]);

    exit(0);
}
