#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid == 0) {
        sleep(2);
        _exit(0);
    }
    if (pid < 0) { perror("fork"); return 1; }

    printf("[1] pid=%d Running\n", pid);
    printf("Bringing job to foreground with waitpid...\n");
    waitpid(pid, NULL, 0);
    printf("[1] Done\n");
    return 0;
}
