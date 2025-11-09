#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>   // fork(), getpid(), write()

#define MAX_COUNT 200
#define BUF_SIZE  100

int main(void) {
    pid_t pid;
    int i;
    char buf[BUF_SIZE];

    if (fork() == -1) {           // simple error check
        perror("fork");
        return 1;
    }

    pid = getpid();
    for (i = 1; i <= MAX_COUNT; i++) {
        int len = snprintf(buf, sizeof(buf),
                           "This line is from pid %d, value = %d\n", pid, i);
        if (len > 0) {
            /* write to STDOUT, ignore return value for brevity */
            write(STDOUT_FILENO, buf, (size_t)len);
        }
    }
    return 0;
}
