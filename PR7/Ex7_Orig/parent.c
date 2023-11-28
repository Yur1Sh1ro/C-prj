#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define SHM_SIZE 1024

int shm_id;          // Идентификатор общей памяти
void *shm_ptr;
pid_t child_pid;     // PID дочернего процесса

void signal_handler(int sig) {
    printf("Signal handler called with signal: %d\n", sig);
    if (sig == SIGUSR1) {
        int sum;
        // Чтение суммы из общей памяти
        memcpy(&sum, shm_ptr, sizeof(int));
        printf("Sum is: %d\n", sum);
    }
}

int main() {
    // Создание общей памяти
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Подключение к общей памяти
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Регистрация обработчика сигнала
    signal(SIGUSR1, signal_handler);

    // Создание дочернего процесса
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // Запуск дочернего процесса
        char shm_id_str[10];
        sprintf(shm_id_str, "%d", shm_id);
        execlp("./child", "child", shm_id_str, NULL);
        perror("execlp");
        exit(1);
    } else {
        while (1) {
            int n, i, input;
            printf("Enter quantity of numbers to sum (0 to exit): ");
            scanf("%d", &n);

            if (n <= 0) {
                break;
            }

            for (i = 0; i < n; i++) {
                printf("Input number: ");
                scanf("%d", &input);
                memcpy(shm_ptr + i * sizeof(int), &input, sizeof(int));
            }

            int end_marker = 0;
            memcpy(shm_ptr + n * sizeof(int), &end_marker, sizeof(int));

            // Отправка сигнала дочернему процессу
            kill(child_pid, SIGUSR1);
            pause();
        }

        // Завершение работы
        kill(child_pid, SIGTERM);
        waitpid(child_pid, NULL, 0);
        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}
