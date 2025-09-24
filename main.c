#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>      // fork, getpid, write

#define MAX_COUNT 200
#define BUF_SIZE  100

int main(void)
{
    pid_t f = fork();
    if (f < 0) {
        perror("fork");
        return 1;
    }

    pid_t pid = getpid();
    char buf[BUF_SIZE];

    for (int i = 1; i <= MAX_COUNT; i++) {
        int n = snprintf(buf, sizeof(buf),
                         "%s line is from pid %d, value = %d\n",
                         (f == 0 ? "Child" : "Parent"),
                         (int)pid, i);
        write(1, buf, (size_t)n);
    }
    return 0;
}
