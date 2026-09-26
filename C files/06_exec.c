#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        perror("execvp");
        _exit(127);
    }

    waitpid(pid, NULL, 0);
    printf("Parent: child completed.\n");
    return 0;
}
