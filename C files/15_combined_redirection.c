#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        int out = open("combined.out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
        if (out < 0) _exit(1);
        dup2(out, STDOUT_FILENO);
        dup2(out, STDERR_FILENO);
        close(out);
        execlp("sh", "sh", "-c", "echo stdout; echo stderr >&2", NULL);
        _exit(127);
    }
    waitpid(pid, NULL, 0);
    puts("stdout and stderr were merged into combined.out");
    return 0;
}
