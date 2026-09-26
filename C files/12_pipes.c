#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    if (pipe(fd) < 0) { perror("pipe"); return 1; }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        close(fd[0]);
        dprintf(fd[1], "Message sent through pipe.\n");
        close(fd[1]);
        _exit(0);
    }

    close(fd[1]);
    char buf[128];
    ssize_t n = read(fd[0], buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    close(fd[0]);
    waitpid(pid, NULL, 0);
    return 0;
}
