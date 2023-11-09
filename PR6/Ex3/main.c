#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// Потокова функція для виведення заданого рядка
void *printString(void *arg) {
    char *str = (char *)arg;
    int repeat = 10; // Кількість разів для виведення

    for (int i = 1; i <= repeat; i++) {
        printf("Thread 1: %s %d\n", str, i);
    }

    pthread_exit(NULL);
}

// Потокова функція для генерації випадкових чисел
void *generateRandomNumbers(void *arg) {
    int range = 100; // Діапазон генерації чисел
    int target = 42; // Задане псевдовипадкове число, при якому потік завершує роботу

    srand(time(NULL)); // Ініціалізуємо генератор випадкових чисел

    while (1) {
        int num = rand() % range;

        printf("Thread 2: Random Number %d\n", num);

        if (num == target) {
            printf("Thread 2: Found the target number %d. Exiting.\n", target);
            break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char *str = "Hello, World";

    pthread_create(&thread1, NULL, printString, str);
    pthread_create(&thread2, NULL, generateRandomNumbers, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main Thread: All child threads have completed.\n");

    return 0;
}