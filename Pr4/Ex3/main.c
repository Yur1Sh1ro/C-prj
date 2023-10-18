#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <environment_variable_name> <value>\n", argv[0]);
        return 1;
    }

    char* var_name = argv[1];
    char* var_value = argv[2];

    if (setenv(var_name, var_value, 1) == 0) {
        printf("Змінну оточення '%s' встановлено на '%s'\n", var_name, var_value);
    } else {
        printf("Помилка при встановленні змінної оточення '%s'\n", var_name);
        return 1;
    }

    char* new_var_value = getenv(var_name);
    if (new_var_value != NULL) {
        printf("Після встановлення, '%s=%s'\n", var_name, new_var_value);
    } else {
        printf("Змінна оточення '%s' не знайдена після встановлення\n", var_name);
    }

    return 0;
}