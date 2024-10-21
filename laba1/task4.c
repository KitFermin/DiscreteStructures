#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Set;

void initSet(Set *set) {
    set->size = 0;
}

bool contains(Set *set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return true;
        }
    }
    return false;
}

void add(Set *set, int value) {
    if (set->size >= MAX_SIZE) {
        printf("Set is full\n");
        return;
    }
    if (!contains(set, value)) {
        set->data[set->size++] = value;
    }
}

void rremove(Set *set, int value) {
    int index = -1;
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < set->size - 1; i++) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

void printSet(Set *set) {
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->data[i]);
    }
    printf("\n");
}

int main() {
    Set set;
    initSet(&set);
    
    add(&set, 10);
    add(&set, 20);
    add(&set, 10); // не добавится, так как 10 уже есть
    
    printSet(&set); // 10 20
    
    rremove(&set, 10);
    
    printSet(&set); // 20

    return 0;
}
