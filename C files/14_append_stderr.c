#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        int fd = open("errors.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) _exit(1);
        dup2(fd, STDERR_FILENO);
        close(fd);
        dprintf(STDERR_FILENO, "This is appended stderr output.\n");
        _exit(0);
    }

    waitpid(pid, NULL, 0);
    puts("Appended to errors.log");
    return 0;
}
