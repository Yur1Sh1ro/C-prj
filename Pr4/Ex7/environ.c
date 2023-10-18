#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Виведення інформації про поточне оточення
        display_environment();
    } else if ((argc == 2) && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        // Виведення довідки
        display_help();
    } else if ((argc == 3) && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0)) {
        // Виведення значення змінної оточення
        display_environment_value(argv[2]);
    } else if ((argc == 4) && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0)) {
        // Встановлення значення змінної оточення
        set_environment_value(argv[2], argv[3]);
    } else if ((argc == 4) && (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--assign") == 0) &&
               (strcmp(argv[3], "--value") == 0)) {
        // Присвоєння значення змінної оточення
        assign_environment_value(argv[2], "");
    } else if ((argc == 5) && (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--assign") == 0) &&
               (strcmp(argv[3], "--value") == 0)) {
        // Присвоєння значення змінної оточення зі значенням
        assign_environment_value(argv[2], argv[4]);
    } else if ((argc == 3) && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0)) {
        // Видалення змінної оточення
        delete_environment_value(argv[2]);
    } else if ((argc == 2) && (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0)) {
        // Очищення оточення
        clear_environment();
    } else {
        // Невідома опція або неправильна кількість аргументів
        display_help();
    }

    return 0;
}