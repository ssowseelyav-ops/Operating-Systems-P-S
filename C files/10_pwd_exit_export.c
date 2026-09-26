#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(void) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)))
        printf("PWD=%s\n", cwd);

    if (setenv("OSSP_DEMO", "hello", 1) != 0) {
        perror("setenv");
        return 1;
    }
    printf("OSSP_DEMO=%s\n", getenv("OSSP_DEMO"));
    return 0;
}
