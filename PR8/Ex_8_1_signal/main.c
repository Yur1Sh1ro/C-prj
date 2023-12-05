#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signalNum) {
    switch(signalNum) {
        case SIGINT:
            printf("Caught SIGINT\n");
            break;
        case SIGTERM:
            printf("Caught SIGTERM\n");
            break;
        case SIGUSR1:
            printf("Caught SIGUSR1\n");
            exit(0);
    }
}

int main() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGUSR1, signalHandler);

    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);

    while(1) {
        pause();
    }
    return 0;
}