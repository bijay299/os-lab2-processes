// main3.c
#include <stdio.h>
#include <stdlib.h>     // srandom, random, exit
#include <unistd.h>     // fork, getpid, getppid, sleep
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait, waitpid
#include <time.h>       // time

#define MAX_ITERS 30
#define MAX_SLEEP 10

static void run_child(void) {
    int i, iters, nap;

    /* Unique seed per child: time XOR pid */
    srandom((unsigned)(time(NULL) ^ getpid()));

    /* 1..MAX_ITERS iterations */
    iters = (int)(random() % MAX_ITERS) + 1;

    for (i = 1; i <= iters; i++) {
        printf("Child Pid: %d is going to sleep!\n", (int)getpid());
        fflush(stdout);

        /* 0..MAX_SLEEP seconds (<=10 as required) */
        nap = (int)(random() % (MAX_SLEEP + 1));
        sleep((unsigned)nap);

        printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",
               (int)getpid(), (int)getppid());
        fflush(stdout);
    }

    exit(0);
}

int main(void) {
    pid_t c1, c2, done;
    int status;

    /* fork first child */
    c1 = fork();
    if (c1 < 0) { perror("fork c1"); return 1; }
    if (c1 == 0) { run_child(); }

    /* fork second child (still in parent) */
    c2 = fork();
    if (c2 < 0) { perror("fork c2"); return 1; }
    if (c2 == 0) { run_child(); }

    /* parent waits for both children */
    while ((done = wait(&status)) > 0) {
        printf("Child Pid: %d has completed\n", (int)done);
        fflush(stdout);
    }

    return 0;
}
