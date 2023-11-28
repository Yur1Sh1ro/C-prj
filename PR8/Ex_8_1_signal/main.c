#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signalNum, siginfo_t *info, void *context) {
    switch (signalNum) {
        case SIGINT:
            printf("Caught SIGINT (^_^)\n");
            break;
        case SIGTERM:
            printf("Caught SIGTERM (^o^)\n");
            break;
        case SIGUSR1:
            printf("Caught SIGUSR1 (*_*)\n");
            exit(0);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = &signalHandler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up SIGINT handler");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error setting up SIGTERM handler");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error setting up SIGUSR1 handler");
        exit(EXIT_FAILURE);
    }

    // Ignore SIGHUP and reset SIGPROF to the default handler
    struct sigaction ignoreSa;
    ignoreSa.sa_handler = SIG_IGN;
    if (sigaction(SIGHUP, &ignoreSa, NULL) == -1) {
        perror("Error setting up SIGHUP handler");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
        perror("Error resetting SIGPROF handler");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return 0;
}