#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmptyQueue(Queue *q) {
    return q->rear < q->front;
}

bool enqueue(Queue *q, int value) {
    if (q->rear >= MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return false;
    }
    q->data[++(q->rear)] = value;
    return true;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->data[q->front++];
}

int first(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printQueue(&q); // 10 20 30
    
    printf("First element: %d\n", first(&q)); // 10
    printf("Dequeued element: %d\n", dequeue(&q)); // 10
    
    printQueue(&q); // 20 30

    return 0;
}
