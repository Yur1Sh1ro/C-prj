#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *child_thread_function(void *arg) {
    int iteration = *((int *)arg);
    for (int i = 0; i < 10; i++) {
        printf("Child Thread. Iteration: %d\n", iteration + 1);
        sleep(rand() % 3); // Засипаємо на випадкову кількість секунд (від 0 до 2)
    }
    return NULL;
}

int main() {
    pthread_t child_thread;
    int iteration = 0;
    
    srand(time(NULL)); // Ініціалізуємо генератор випадкових чисел

    for (iteration = 0; iteration < 10; iteration++) {
        printf("Main Thread. Iteration: %d\n", iteration + 1);

        if (pthread_create(&child_thread, NULL, child_thread_function, &iteration) != 0) {
            fprintf(stderr, "Помилка при створенні дочірнього потоку.\n");
            return 1;
        }

        pthread_join(child_thread, NULL); // Чекаємо завершення дочірнього потоку
        sleep(rand() % 3); // Засипаємо головний потік
    }

    return 0;
}