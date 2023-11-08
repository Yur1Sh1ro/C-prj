#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Введіть команди для виконання через крапку з комою (;).\n");
        return 1;
    }

    char command[256] = "";
    for (int i = 1; i < argc; i++) {
        strcat(command, argv[i]);
        if (i < argc - 1) {
            strcat(command, " ");
        }
    }

    char *token = strtok(command, ";");
    while (token != NULL) {
        int status = system(token);
        printf("Код завершення команди \"%s\": %d\n", token, status);
        token = strtok(NULL, ";");
    }

    return 0;
}