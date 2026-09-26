#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) { perror("open"); _exit(1); }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execlp("echo", "echo", "Hello via stdout redirection", NULL);
        perror("execlp");
        _exit(127);
    }

    waitpid(pid, NULL, 0);
    puts("Created output.txt");
    return 0;
}
