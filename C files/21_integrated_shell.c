#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char line[256];

    while (1) {
        printf("ossp-shell> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = '\0';

        if (!strcmp(line, "exit")) break;
        if (!strcmp(line, "")) continue;

        if (!strcmp(line, "cd")) {
            const char *home = getenv("HOME");
            if (chdir(home ? home : "/") < 0) perror("cd");
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) { perror("fork"); continue; }

        if (pid == 0) {
            execl("/bin/sh", "sh", "-c", line, NULL);
            perror("exec");
            _exit(127);
        }
        waitpid(pid, NULL, 0);
    }
    return 0;
}
