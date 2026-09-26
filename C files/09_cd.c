#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

int main(void) {
    char before[PATH_MAX], after[PATH_MAX];
    if (!getcwd(before, sizeof(before))) { perror("getcwd"); return 1; }

    if (chdir(getenv("HOME") ? getenv("HOME") : "/") != 0) {
        perror("chdir");
        return 1;
    }

    if (!getcwd(after, sizeof(after))) { perror("getcwd"); return 1; }
    printf("Before: %s\nAfter:  %s\n", before, after);
    return 0;
}
