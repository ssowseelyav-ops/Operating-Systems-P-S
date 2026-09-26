#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char line[512];

    while (1) {
        printf("ossp-shell> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = '\0';

        if (!strcmp(line, "exit")) break;

        if (!strcmp(line, "pwd")) {
            char cwd[4096];
            if (getcwd(cwd, sizeof(cwd))) puts(cwd);
            else perror("pwd");
            continue;
        }

        if (!strcmp(line, "cd")) {
            const char *home = getenv("HOME");
            if (chdir(home ? home : "/") < 0) perror("cd");
            continue;
        }

        if (!*line) continue;

        pid_t pid = fork();
        if (pid < 0) { perror("fork"); continue; }

        if (pid == 0) {
            execl("/bin/sh", "sh", "-c", line, NULL);
            perror("exec");
            _exit(127);
        }

        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            fprintf(stderr, "Command exited with status %d\n", WEXITSTATUS(status));
    }

    puts("Goodbye.");
    return 0;
}
