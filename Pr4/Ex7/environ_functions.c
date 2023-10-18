#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void display_environment() {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

void display_environment_value(const char *variable) {
    char *value = getenv(variable);
    if (value != NULL) {
        printf("%s=%s\n", variable, value);
    } else {
        printf("Змінна оточення '%s' не знайдена\n", variable);
    }
}

void set_environment_value(const char *variable, const char *value) {
    if (setenv(variable, value, 1) == 0) {
        printf("Змінну оточення '%s' встановлено на '%s'\n", variable, value);
    } else {
        printf("Помилка при встановленні змінної оточення '%s'\n", variable);
    }
}

void assign_environment_value(const char *variable, const char *value) {
    if (setenv(variable, value, 1) == 0) {
        printf("Змінну оточення '%s' присвоєно нове значення '%s'\n", variable, value);
    } else {
        printf("Помилка при присвоєнні значення змінній оточення '%s'\n", variable);
    }
}

void delete_environment_value(const char *variable) {
    if (unsetenv(variable) == 0) {
        printf("Змінну оточення '%s' видалено\n", variable);
    } else {
        printf("Помилка при видаленні змінної оточення '%s'\n", variable);
    }
}

void clear_environment() {
    clearenv();
    printf("Оточення було очищено\n");
}

void display_help() {
    printf("Usage: environ [options]\n");
    printf("Options:\n");
    printf("  -h, --help               Вивести цю довідку\n");
    printf("  -i, --info <variable>    Вивести значення змінної оточення\n");
    printf("  -s, --set <variable=value> Встановити значення змінної оточення\n");
    printf("  -a, --assign <variable> [--value <value>] Присвоїти значення змінній оточення\n");
    printf("  -d, --del <variable>     Видалити змінну оточення\n");
    printf("  -c, --clear              Очистити оточення\n");
}
