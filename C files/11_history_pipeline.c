#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 10

int main(void) {
    char *history[MAX_HISTORY] = {0};
    char buf[128];
    int count = 0;

    printf("Enter commands (type 'done' to finish):\n");
    while (count < MAX_HISTORY && fgets(buf, sizeof(buf), stdin)) {
        buf[strcspn(buf, "\n")] = '\0';
        if (!strcmp(buf, "done")) break;
        history[count++] = strdup(buf);
    }

    puts("\nHistory:");
    for (int i = 0; i < count; ++i) {
        printf("%d  %s\n", i + 1, history[i]);
        free(history[i]);
    }

    puts("\nPipeline representation: command1 | command2 | command3");
    return 0;
}
