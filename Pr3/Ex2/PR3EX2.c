#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    int size;
};

struct LinkedList* createLinkedList() {
    struct LinkedList *list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(struct LinkedList *list, int item) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void insert(struct LinkedList *list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Недопустимий індекс для вставки.\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
}

int size(struct LinkedList *list) {
    return list->size;
}

void removeIndex(struct LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для видалення.\n");
        return;
    }

    struct Node *temp = list->head;
    if (index == 0) {
        list->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        struct Node *nodeToRemove = temp->next;
        temp->next = nodeToRemove->next;
        free(nodeToRemove);
    }

    list->size--;
}

void set(struct LinkedList *list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для заміни.\n");
        return;
    }

    struct Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = item;
}

int get(struct LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Недопустимий індекс для отримання.\n");
        return -1;
    }

    struct Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

void printList(struct LinkedList *list) {
    struct Node *current = list->head;
    printf("Елементи списку: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(struct LinkedList *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    struct LinkedList *list = createLinkedList();

    add(list, 1);
    add(list, 2);
    add(list, 3);
    printList(list);

    insert(list, 1, 4);
    printList(list);

    printf("Кількість елементів у списку: %d\n", size(list));

    removeIndex(list, 2);
    printList(list);

    set(list, 0, 5);
    printList(list);

    int value = get(list, 1);
    printf("Значення елемента з індексом 1: %d\n", value);

    freeLinkedList(list);

    return 0;
}