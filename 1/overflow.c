#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CLOCKS_PER_SEC 100.0

int main(void) {
    time_t calt;
    float  days;

    calt = (time_t) 0x7fffffffL;
    printf("calendar overflow: %s",ctime(&calt));
    days = (0x7fffffffL / _CLOCKS_PER_SEC) / 60.0 / 60.0 / 24.0;
    printf("process time overflow: %02.2f days\n", days);

    exit(0);
}

