#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        setpgid(0, 0);
        printf("Child process group: %d\n", getpgrp());
        sleep(10);
        _exit(0);
    }

    setpgid(pid, pid);
    printf("Created process group %d\n", pid);
    sleep(1);
    kill(-pid, SIGTERM);
    waitpid(pid, NULL, 0);
    puts("Process group terminated.");
    return 0;
}
