#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#include "error.h"

#define MAXLINE 4096

static void sig_int(int);

int main(void) {
    char  buf[MAXLINE];
    pid_t pid;
    int   status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0'; /* replace newline with null */
        
        if (( pid = fork() ) < 0) {
            err_sys("fork error");
        }
        else if ( pid == 0 ) { /* child process */
            if ( execlp(buf, buf, (char *) 0) == -1)
                err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ( ( pid = waitpid(pid, &status, 0) ) < 0)
            err_sys("waitpid error");

        printf("%% ");
    }

    if (ferror(stdin))
        err_sys("fgets error");

    exit(0);
}

void sig_int(int signo) {
    printf("interrupt\n%% ");
}
