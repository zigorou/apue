#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "error.h";

#define MAXLINE 1000

void err_doit(int useerrno, const char *fmt, va_list ap) {
    int errno_orig;
    char buf[MAXLINE + 1];

    errno_orig = errno;
    vsnprintf(buf, MAXLINE, fmt, ap);
    if (useerrno) {
        strcat(buf, ": ");
        strcat(buf, strerror(errno_orig));
    }
    strcat(buf, "\n");
    fputs(buf, stderr);

    return;
}

void err_quit(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    err_doit(0, fmt, ap);
    va_end(ap);
    exit(1);
}

void err_sys(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, fmt, ap);
    va_end(ap);
    exit(1);
}
