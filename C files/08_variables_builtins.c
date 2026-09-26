#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *path = getenv("PATH");
    const char *home = getenv("HOME");
    printf("HOME=%s\n", home ? home : "(undefined)");
    printf("PATH=%s\n", path ? path : "(undefined)");
    printf("Built-ins can be dispatched without creating a child process.\n");
    return 0;
}
