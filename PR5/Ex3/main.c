#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 127

void print_help() {
    printf("Спрощений командний процесор\n");
    printf("Доступні команди:\n");
    printf("  stop - завершення роботи програми\n");
    printf("  clear - очистити екран\n");
    printf("  help - вивести довідку\n");
    printf("Для виконання інших команд введіть їх безпосередньо.\n");
}

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER_SIZE + 1];
    char *user = getenv("USER"); // Отримуємо ім'я поточного користувача

    if (user == NULL) {
        user = "user"; // Якщо ім'я користувача не знайдено, встановлюємо значення за замовчуванням
    }

    printf("Ласкаво просимо, %s!\n", user);

    while (1) {
        printf("[%s]$", user);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0'; // Видаляємо символ нового рядка

        if (strcmp(buffer, "stop") == 0) {
            printf("Завершення роботи програми...\n");
            sleep(3);
            break;
        } else if (strcmp(buffer, "clear") == 0) {
            system("clear");
        } else if (strcmp(buffer, "help") == 0) {
            print_help();
        } else {
            int status = system(buffer);
            if (status == 0) {
                printf("Команда виконана успішно.\n");
            } else {
                printf("Помилка виконання команди. Код завершення: %d\n", status);
            }
        }
    }

    printf("Завершення програми...\n");
    sleep(3);
    system("clear");

    return 0;
}