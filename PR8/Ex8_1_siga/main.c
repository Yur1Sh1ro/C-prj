#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signalNum) {
    switch(signalNum) {
        case SIGINT:
            printf("Caught SIGINT \n");
            break;
        case SIGTERM:
            printf("Caught SIGTERM \n");
            break;
        case SIGUSR1:
            printf("Caught SIGUSR1  \n");
            exit(0);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);

    while(1) {
        pause();
    }
    return 0;
}