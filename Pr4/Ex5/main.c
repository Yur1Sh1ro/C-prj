#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>

int main() {
    struct passwd *current_user = getpwuid(getuid());
    if (current_user != NULL) {
        printf("Інформація про поточного користувача:\n");
        printf("Ім'я користувача: %s\n", current_user->pw_name);
        printf("Повне ім'я: %s\n", current_user->pw_gecos);
        printf("Домашній каталог: %s\n", current_user->pw_dir);
        printf("Шлях до оболонки: %s\n", current_user->pw_shell);
    } else {
        printf("Помилка при отриманні інформації про поточного користувача\n");
    }

    struct passwd *root_user = getpwnam("root");
    if (root_user != NULL) {
        printf("\nІнформація про користувача 'root':\n");
        printf("Ім'я користувача: %s\n", root_user->pw_name);
        printf("Повне ім'я: %s\n", root_user->pw_gecos);
        printf("Домашній каталог: %s\n", root_user->pw_dir);
        printf("Шлях до оболонки: %s\n", root_user->pw_shell);
    } else {
        printf("\nПомилка при отриманні інформації про користувача 'root'\n");
    }

    return 0;
}