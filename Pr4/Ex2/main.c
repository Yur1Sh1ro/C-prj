#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    char* var_name = argv[1];
    char* var_value = getenv(var_name);

    if (var_value != NULL) {
        printf("%s=%s\n", var_name, var_value);
    } else {
        printf("Змінна оточення '%s' не знайдена\n", var_name);
    }

    return 0;
}