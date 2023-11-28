#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int sig) {
    // empty
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Использование: %s <время в секундах> <сообщение>\n", argv[0]);
        return 1;
    }

    int time = atoi(argv[1]);
    char *message = argv[2];

    pid_t pid = fork();

    if (pid < 0) {
        perror("Ошибка при вызове fork");
        exit(1);
    }

    if (pid == 0) {
        // дочерний процесс
        signal(SIGALRM, alarmHandler);
        alarm(time);
        pause();
        printf("Сигнал будильника: %s\n", message);
        exit(0);
    } else {
        // родительский процесс
        printf("Будильник установлен на %d секунд. PID процесса будильника: %d\n", time, pid);
        exit(0);
    }
    return 0;
}