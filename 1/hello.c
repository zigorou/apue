#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("hello world from process ID %d\n", getpid());
    exit(0);
}
