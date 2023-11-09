#include <stdio.h>
#include <pthread.h>

// Функція, яку виконуватимуть потоки
void *threadFunction(void *arg) {
    char *name = ((char **)arg)[0];
    char *str = ((char **)arg)[1];
    int num = *((int *)arg);

    for (int i = 1; i <= num; i++) {
        printf("Thread %s. %s %d\n", name, str, i);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    char *names[4] = {"A", "B", "C", "D"};
    char *str = "Hello";
    int num = 5;

    for (int i = 0; i < 4; i++) {
        char *args[2] = {names[i], str};
        pthread_create(&threads[i], NULL, threadFunction, args);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}