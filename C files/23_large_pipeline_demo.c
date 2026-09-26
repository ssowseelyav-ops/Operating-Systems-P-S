#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int commands = 5;
    printf("Large pipeline demo: %d stages\n", commands);
    printf("Typical structure: cmd1 | cmd2 | cmd3 | cmd4 | cmd5\n");
    printf("Measure runtime with: /usr/bin/time ./23_large_pipeline_demo\n");
    return 0;
}
