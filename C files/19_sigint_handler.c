#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void on_sigint(int sig) {
    (void)sig;
    write(STDOUT_FILENO, "\nSIGINT received. Shell remains active.\n", 38);
}

int main(void) {
    struct sigaction sa = {0};
    sa.sa_handler = on_sigint;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("PID %d: press Ctrl-C.\n", getpid());
    while (1) pause();
    return 0;
}
