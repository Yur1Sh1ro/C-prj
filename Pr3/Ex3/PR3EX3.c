#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double sum = 0.0;
    int count = 0;
    int firstNegativeFound = 0;
    double sumOfMods = 0.0;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Розмір масиву повинен бути додатнім числом.\n");
        return 1;
    }
    double arr[n];
    printf("Введіть %d дійсних чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
        if (arr[i] > 0) {
            count++;
        }
        if (firstNegativeFound) {
            sumOfMods += fabs(arr[i]);
        }
        if (arr[i] < 0) {
            firstNegativeFound = 1;
        }
    }
    if (firstNegativeFound == 0) {
        printf("Перший від'ємний елемент не знайдено.\n");
    } else {
        printf("Кількість елементів, більших за середнє значення: %d\n", count);
        printf("Сума модулів елементів після першого від'ємного: %.2lf\n", sumOfMods);
    }

    return 0;
}