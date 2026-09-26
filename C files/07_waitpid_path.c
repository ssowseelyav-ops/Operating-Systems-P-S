#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        execlp("echo", "echo", "Hello from child", NULL);
        perror("execlp");
        _exit(127);
    }

    int status;
    if (waitpid(pid, &status, 0) < 0) { perror("waitpid"); return 1; }
    if (WIFEXITED(status))
        printf("Child exit status: %d\n", WEXITSTATUS(status));
    return 0;
}
