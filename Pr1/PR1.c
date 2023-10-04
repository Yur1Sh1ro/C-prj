#include <stdio.h>
#include <string.h>

// Максимальна кількість студентів
#define MAX_STUDENTS 10

// Структура, що представляє студента
struct Student {
    char name[50];
    int age;
    char department[50];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    printf("Ласкаво просимо до програми для створення колекції студентів!\n");

    while (1) {
        printf("Оберіть опцію:\n");
        printf("1. Додати студента\n");
        printf("2. Показати колекцію студентів\n");
        printf("3. Вийти\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            if (numStudents < MAX_STUDENTS) {
                printf("Введіть ім'я студента: ");
                scanf("%s", students[numStudents].name);
                printf("Введіть вік студента: ");
                scanf("%d", &students[numStudents].age);
                printf("Введіть факультет студента: ");
                scanf("%s", students[numStudents].department);
                numStudents++;
                printf("Студент доданий до колекції.\n");
            } else {
                printf("Колекція студентів заповнена. Неможливо додати більше студентів.\n");
            }
        } else if (option == 2) {
            printf("Колекція студентів:\n");
            for (int i = 0; i < numStudents; i++) {
                printf("Студент %d:\n", i + 1);
                printf("Ім'я: %s\n", students[i].name);
                printf("Вік: %d\n", students[i].age);
                printf("Факультет: %s\n", students[i].department);
            }
        } else if (option == 3) {
            printf("Exit!\n");
            break;
        } else {
            printf("Невірний вибір опції. Будь ласка, спробуйте ще раз.\n");
        }
    }

    return 0;
}