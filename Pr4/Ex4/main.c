#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if (unsetenv(argv[1]) == 0) {
            printf("Змінну оточення '%s' видалено\n", argv[1]);
        } else {
            printf("Помилка при видаленні змінної оточення '%s'\n", argv[1]);
            return 1;
        }
    } else if (argc == 1) {
        if (clearenv() == 0) {
            printf("Оточення було очищено\n");
        } else {
            printf("Помилка при очищенні оточення\n");
            return 1;
        }
    } else {
        printf("Usage: %s [environment_variable_name]\n", argv[0]);
        return 1;
    }

    extern char** environ;
    for (char** env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}