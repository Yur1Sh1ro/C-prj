#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int sig) {
    // empty
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <time in seconds> <message>\n", argv[0]);
        return 1;
    }

    int time = atoi(argv[1]);
    char *message = argv[2];

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // child
        signal(SIGALRM, alarmHandler);
        alarm(time);
        pause();
        printf("Alarm: %s\n", message);
        exit(0);
    } else {
        // parent
        printf("Alarm set for %d seconds. PID of alarm process: %d\n", time, pid);
        exit(0);
    }
    return 0;
}