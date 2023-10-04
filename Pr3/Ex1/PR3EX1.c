#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

struct ArrayList {
    int *data;
    int size;
    int capacity;
};

struct ArrayList* createArrayList() {
    struct ArrayList *list = (struct ArrayList*)malloc(sizeof(struct ArrayList));
    list->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void ensureCapacity(struct ArrayList *list) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
}

void add(struct ArrayList *list, int item) {
    ensureCapacity(list);
    list->data[list->size] = item;
    list->size++;
}

void insert(struct ArrayList *list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Недопустимий індекс для вставки.\n");
        return;
    }

    ensureCapacity(list);
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = item;
    list->size++;
}

int size(struct ArrayList *list) {
    return list->size;
}

void removeIndex(struct ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для видалення.\n");
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

void set(struct ArrayList *list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для заміни.\n");
        return;
    }

    list->data[index] = item;
}

int get(struct ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для отримання.\n");
        return -1; 
    }

    return list->data[index];
}

void display(struct ArrayList *list) {
    printf("Елементи списку: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void freeArrayList(struct ArrayList *list) {
    free(list->data);
    free(list);
}

int main() {
    struct ArrayList *list = createArrayList();

    add(list, 1);
    add(list, 2);
    add(list, 3);
    display(list);

    insert(list, 1, 4);
    display(list);

    printf("Кількість елементів у списку: %d\n", size(list));

    removeIndex(list, 2);
    display(list);

    set(list, 0, 5);
    display(list);

    int value = get(list, 1);
    printf("Значення елемента з індексом 1: %d\n", value);

    freeArrayList(list);

    return 0;
}
