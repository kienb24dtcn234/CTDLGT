#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        free(queue);
        return NULL;
    }
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->rear < queue->front);
}

int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("queue is full\n");
        return;
    }
    queue->rear = queue->rear + 1;
    queue->array[queue->rear] = data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("queue is empty\n");
        return -1;
    }
    int data = queue->array[queue->front];
    queue->front = queue->front + 1;
    return data;
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("queue is empty\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->array[i]);
    }
}

int main() {
    int max_capacity = 5;
    Queue* myQueue = createQueue(max_capacity);

    if (myQueue != NULL) {
        printf("Queue khoi tao thanh cong\n");

        printf("Hang doi rong luc ban dau: %s\n", isEmpty(myQueue) ? "true" : "false");
        printf("Display queue when empty:\n");
        displayQueue(myQueue);

        for (int i = 0; i < 3; i++) {
            enqueue(myQueue, i + 1);
        }

        printf("Hang doi rong sau khi them phan tu: %s\n", isEmpty(myQueue) ? "true" : "false");

        printf("Queue sau khi them 3 phan tu:\n");
        printf("array = [");
        for (int i = myQueue->front; i <= myQueue->rear; i++) {
            printf("%d", myQueue->array[i]);
            if (i < myQueue->rear) {
                printf(", ");
            }
        }
        printf("],\n");
        printf("front = %d,\n", myQueue->front);
        printf("rear = %d,\n", myQueue->rear);
        printf("capacity = %d\n", myQueue->capacity);
        printf("Display queue with elements:\n");
        displayQueue(myQueue);
        printf("Gia tri lay ra: %d\n", dequeue(myQueue));
        printf("Gia tri lay ra: %d\n", dequeue(myQueue));
        printf("Gia tri lay ra: %d\n", dequeue(myQueue));
        printf("Gia tri lay ra: %d\n", dequeue(myQueue));

        free(myQueue->array);
        free(myQueue);
    } else {
        printf("Khoi tao queue that bai\n");
    }

    return 0;
}