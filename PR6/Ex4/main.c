#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Функція для обчислення чисел Каталана
void *calculateCatalan(void *arg) {
    int n = *((int *)arg);
    unsigned long long catalan[100];
    catalan[0] = 1;

    for (int i = 1; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    printf("Перші %d чисел Каталана: ", n);
    for (int i = 0; i < n; i++) {
        printf("%llu ", catalan[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

// Допоміжна функція для перевірки, чи число є простим
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }

    return 1;
}

// Функція для обчислення перших n простих чисел
void *calculatePrimes(void *arg) {
    int n = *((int *)arg);
    int primes[100];
    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }

    printf("Перші %d простих чисел: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int n1 = 10; // Кількість чисел Каталана
    int n2 = 20; // Кількість простих чисел

    pthread_create(&thread1, NULL, calculateCatalan, &n1);
    pthread_create(&thread2, NULL, calculatePrimes, &n2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}