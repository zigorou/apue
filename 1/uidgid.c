#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
