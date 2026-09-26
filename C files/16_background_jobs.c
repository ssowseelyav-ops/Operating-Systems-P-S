#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        sleep(3);
        printf("Background job %d finished.\n", getpid());
        _exit(0);
    }

    printf("[1] %d running in background\n", pid);
    printf("Parent immediately returns to the prompt.\n");
    waitpid(pid, NULL, 0);
    return 0;
}
