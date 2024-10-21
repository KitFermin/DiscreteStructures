#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} List;

void initList(List *list) {
    list->size = 0;
}

void add(List *list, int index, int value) {
    if (list->size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

void removeAt(List *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

void printList(List *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    List list;
    initList(&list);
    
    add(&list, 0, 10);
    add(&list, 1, 20);
    add(&list, 1, 30);
    
    printList(&list); // 10 30 20
    
    removeAt(&list, 1);
    
    printList(&list); // 10 20

    return 0;
}
