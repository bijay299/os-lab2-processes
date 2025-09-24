#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_COUNT 200

void ChildProcess(void) {
    int i;
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("   Child (pid %d): value = %d\n", (int)getpid(), i);
    }
}

void ParentProcess(void) {
    int i;
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("Parent (pid %d): value = %d\n", (int)getpid(), i);
    }
}

int main(void) {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        ChildProcess();   // child runs this
        _exit(0);         // exit cleanly
    } else {
        ParentProcess();  // parent runs this
        int status;
        waitpid(pid, &status, 0); // parent waits for child
    }

    return 0;
}
