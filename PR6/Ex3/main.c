#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Функція для генерації псевдовипадкових чисел і виведення їх
void *random_number_thread(void *args) {
    int num = *((int *)args);
    
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    for (int i = 0; i < num; i++) {
        int random_num = rand() % 100; // Генеруємо випадкове число від 0 до 99
        printf("Random Thread. Number: %d\n", random_num);

        if (random_num == 42) {
            printf("Random Thread. Found the meaning of life (42) and exiting.\n");
            pthread_exit(NULL);
        }

        sleep(1); // Засипаємо потік на 1 секунду
    }

    pthread_exit(NULL);
}

// Функція для виведення заданого рядка задану кількість разів
void *string_thread(void *args) {
    struct ThreadArgs {
        char *str;
        int num;
    };
    struct ThreadArgs *thread_args = (struct ThreadArgs *)args;

    for (int i = 0; i < thread_args->num; i++) {
        printf("String Thread. String: %s\n", thread_args->str);
        sleep(1); // Засипаємо потік на 1 секунду
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t random_thread, string_thread;
    int num_random = 20; // Кількість випадкових чисел для генерації
    int num_strings = 10; // Кількість повторень рядка

    // Створюємо потоки та передаємо їм параметри
    if (pthread_create(&random_thread, NULL, random_number_thread, &num_random) != 0) {
        fprintf(stderr, "Помилка при створенні потоку для генерації чисел.\n");
        return 1;
    }

    struct ThreadArgs string_args = {"Hello, World!", num_strings};
    if (pthread_create(&string_thread, NULL, string_thread, &string_args) != 0) {
        fprintf(stderr, "Помилка при створенні потоку для рядків.\n");
        return 1;
    }

    // Чекаємо завершення обох потоків
    pthread_join(random_thread, NULL);
    pthread_join(string_thread, NULL);

    printf("Main Thread. All child threads have finished.\n");

    return 0;
}