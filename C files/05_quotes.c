#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[256];
    printf("mini-shell> ");
    if (!fgets(input, sizeof(input), stdin)) return 0;
    input[strcspn(input, "\n")] = '\0';

    printf("Input: %s\n", input);
    printf("Single quotes preserve literal text; double quotes allow $ expansion.\n");
    return 0;
}
