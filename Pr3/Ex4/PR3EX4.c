#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введіть кількість матеріальних точок: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Кількість точок повинна бути додатнім числом.\n");
        return 1;
    }
    int *points = (int *)malloc(n * sizeof(int));
    if (points == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Введіть масу точки %d: ", i + 1);
        scanf("%d", &points[i]);
    }
    while (n > 1) {
        int minMassIndex = 0;
        for (int i = 1; i < n; i++) {
            if (points[i] < points[minMassIndex]) {
                minMassIndex = i;
            }
        }
        int nearestPointIndex = (minMassIndex == 0) ? 1 : 0;
        int minDistance = abs(minMassIndex - nearestPointIndex);
        for (int i = 0; i < n; i++) {
            if (i != minMassIndex) {
                int distance = abs(i - minMassIndex);
                if (distance < minDistance) {
                    nearestPointIndex = i;
                    minDistance = distance;
                }
            }
        }
        points[nearestPointIndex] += points[minMassIndex];
        for (int i = minMassIndex; i < n - 1; i++) {
            points[i] = points[i + 1];
        }
        n--;
    }
    printf("Залишена точка має масу %d.\n", points[0]);
    free(points);
    return 0;
}