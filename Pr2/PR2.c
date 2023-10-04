#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomDigit() {
    return rand() % 10;
}

int main() {
    srand(time(0));
    int stavka = 10;
    int digit1 = generateRandomDigit();
    int digit2 = generateRandomDigit();
    int digit3 = generateRandomDigit();
    printf("Випадкова послідовність цифр: %d %d %d\n", digit1, digit2, digit3);
    if (digit1 == 7 || digit2 == 7 || digit3 == 7) {
        printf("Ви виграли %d гривень! Ваша ставка повернулася.\n", stavka);
    } else if (digit1 == digit2 && digit2 == digit3) {
        stavka *= 2;
        printf("Ви виграли %d гривень! Ваша ставка подвоєна.\n", stavka);
    } else if (digit1 == digit2 || digit2 == digit3 || digit1 == digit3) {
        printf("Ви виграли %d гривень! Ваша ставка повернулася.\n", stavka);
    } else {
        printf("Ви програли %d гривень.\n", stavka);
    }

    return 0;
}