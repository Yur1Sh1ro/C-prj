#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void process_handler(int signum) {
    printf("Обробник завершення процесу викликаний для сигналу %d\n", signum);
    sleep(1); // Призупинити роботу обробника на 1 секунду
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Використання: %s <кількість_обробників>\n", argv[0]);
        return 1;
    }

    int num_handlers = atoi(argv[1]);
    
    if (num_handlers <= 0) {
        printf("Невірний аргумент: кількість_обробників має бути додатнім числом.\n");
        return 1;
    }

    for (int i = 1; i <= num_handlers; i++) {
        if (signal(SIGINT, process_handler) == SIG_ERR) {
            printf("Помилка при налаштуванні обробника завершення процесу.\n");
            return 1;
        }
    }

    printf("Зареєстровано %d обробників завершення процесу.\n", num_handlers);

    while (1) {
        // Безкінечний цикл для збереження програми активною
    }

    return 0;
}