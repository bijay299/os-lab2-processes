#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>   // fork()

#define MAX_COUNT 200

void ChildProcess(void);   // child process prototype
void ParentProcess(void);  // parent process prototype

int main(void)
{
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        ChildProcess();
    } else {
        ParentProcess();
    }
    return 0;
}

void ChildProcess(void)
{
    for (int i = 1; i <= MAX_COUNT; i++)
        printf("   This line is from child, value = %d\n", i);
    printf("   *** Child process is done ***\n");
}

void ParentProcess(void)
{
    for (int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    printf("*** Parent is done ***\n");
}
