#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *p = malloc(10 * sizeof(*p));
    if (!p) return 1;

    for (int i = 0; i < 10; ++i) p[i] = i;
    printf("Allocated and initialized memory.\n");

    free(p);
    return 0;
}
