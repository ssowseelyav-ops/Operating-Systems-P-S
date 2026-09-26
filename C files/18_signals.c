#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t got_signal = 0;

static void handler(int sig) {
    got_signal = sig;
}

int main(void) {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);

    printf("PID %d. Press Ctrl-C or send SIGTERM.\n", getpid());
    while (!got_signal) pause();

    printf("Received signal %d; exiting.\n", got_signal);
    return 0;
}
