#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Функція для обчислення перших чисел Каталана
void calculate_catalan_numbers(int n, unsigned long long *catalan_numbers) {
    catalan_numbers[0] = 1;

    for (int i = 1; i < n; i++) {
        catalan_numbers[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan_numbers[i] += catalan_numbers[j] * catalan_numbers[i - j - 1];
        }
    }
}

// Функція для перевірки, чи число є простим
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }

    return 1;
}

// Функція для обчислення перших простих чисел
void calculate_prime_numbers(int n, int *prime_numbers) {
    int count = 0;
    int current_number = 2;

    while (count < n) {
        if (is_prime(current_number)) {
            prime_numbers[count] = current_number;
            count++;
        }
        current_number++;
    }
}

int main() {
    int n = 10; // Кількість чисел Каталана та простих чисел, які потрібно обчислити
    unsigned long long catalan_numbers[n];
    int prime_numbers[n];
    
    pthread_t catalan_thread, prime_thread;

    // Створюємо поток для обчислення чисел Каталана
    if (pthread_create(&catalan_thread, NULL, (void *(*)(void *))calculate_catalan_numbers, &n) != 0) {
        fprintf(stderr, "Помилка при створенні потоку для обчислення чисел Каталана.\n");
        return 1;
    }

    // Створюємо поток для обчислення простих чисел
    if (pthread_create(&prime_thread, NULL, (void *(*)(void *))calculate_prime_numbers, &n) != 0) {
        fprintf(stderr, "Помилка при створенні потоку для обчислення простих чисел.\n");
        return 1;
    }

    // Очікуємо завершення обох потоків
    pthread_join(catalan_thread, NULL);
    pthread_join(prime_thread, NULL);

    // Виводимо обчислені числа
    printf("Перші %d чисел Каталана: ", n);
    for (int i = 0; i < n; i++) {
        printf("%llu ", catalan_numbers[i]);
    }
    printf("\n");

    printf("Перші %d простих чисел: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", prime_numbers[i]);
    }
    printf("\n");

    return 0;
}
