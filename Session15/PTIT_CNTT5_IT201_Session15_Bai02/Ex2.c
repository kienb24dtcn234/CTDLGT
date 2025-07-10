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

int main() {
    int max_capacity = 5;
    Queue* myQueue = createQueue(max_capacity);

    if (myQueue != NULL) {
        printf("Queue khoi tao thanh cong\n");

        for (int i = 0; i < 5; i++) {
            int value;
            printf("Nhap gia tri phan tu thu %d: ", i + 1);
            scanf("%d", &value);
            enqueue(myQueue, value);
        }
        printf("Queue sau khi them 5 phan tu:\n");
        printf("array = [");
        for (int i = 0; i <= myQueue->rear; i++) {
            printf("%d", myQueue->array[i]);
            if (i < myQueue->rear) {
                printf(", ");
            }
        }
        printf("],\n");
        printf("front = %d,\n", myQueue->front);
        printf("rear = %d,\n", myQueue->rear);
        printf("capacity = %d\n", myQueue->capacity);

        free(myQueue->array);
        free(myQueue);
    } else {
        printf("Khoi tao queue that bai\n");
    }

    return 0;
}