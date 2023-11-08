#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *args) {
    // Розпаковуємо параметри зі структури
    struct ThreadArgs {
        char *name;
        char *str;
        int num;
    };
    struct ThreadArgs *thread_args = (struct ThreadArgs *)args;
    
    // Виводимо повідомлення з відповідними параметрами
    for (int i = 1; i <= thread_args->num; i++) {
        printf("Thread %s. Str %d\n", thread_args->name, i);
    }
    
    return NULL;
}

int main() {
    // Створюємо 4 набори параметрів для потоків
    struct ThreadArgs thread_args[4] = {
        {"A", "Hello", 3},
        {"B", "World", 4},
        {"C", "OpenAI", 2},
        {"D", "Example", 5}
    };

    pthread_t threads[4];
    
    // Створюємо 4 потоки та передаємо їм параметри
    for (int i = 0; i < 4; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            fprintf(stderr, "Помилка при створенні потоку.\n");
            return 1;
        }
    }

    // Чекаємо завершення кожного потоку
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}