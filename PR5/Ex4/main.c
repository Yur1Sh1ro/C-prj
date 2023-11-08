#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_FILE_NAME "output"
#define MAX_FILE_NAME_LENGTH 256

void generate_random_numbers(const char *file_name, int program_number, int count) {
    char filename[MAX_FILE_NAME_LENGTH];

    if (file_name == NULL) {
        snprintf(filename, sizeof(filename), "%s%d.txt", DEFAULT_FILE_NAME, program_number);
    } else {
        snprintf(filename, sizeof(filename), "%s%d.txt", file_name, program_number);
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Помилка відкриття файлу");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int random_number = rand() % 2;
        fprintf(file, "%d\n", random_number);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    char *file_name = NULL;
    int program_count = 1;
    int number_of_randoms = 10; // За замовчуванням генеруємо 10 випадкових чисел

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if (i + 1 < argc) {
                file_name = argv[i + 1];
                i++; // Пропустимо наступний аргумент, який є ім'ям файлу
            } else {
                printf("Помилка: не вказано ім'я файлу після опції -f (--file).\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0) {
            if (i + 1 < argc) {
                program_count = atoi(argv[i + 1]);
                i++; // Пропустимо наступний аргумент, який є кількістю дочірніх програм
            } else {
                printf("Помилка: не вказано кількість дочірніх програм після опції -n (--number).\n");
                return 1;
            }
        }
    }

    for (int i = 1; i <= program_count; i++) {
        generate_random_numbers(file_name, i, number_of_randoms);
        printf("Дочірня програма %d: створено файл з випадковими числами.\n", i);
    }

    return 0;
}