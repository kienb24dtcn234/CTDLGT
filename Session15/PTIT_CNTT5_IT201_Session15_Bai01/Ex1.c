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

int main() {
    int max_capacity = 5;
    Queue* myQueue = createQueue(max_capacity);

    if (myQueue != NULL) {
        printf("Queue khoi tao thanh cong\n");
        free(myQueue->array);
        free(myQueue);
    } else {
        printf("Khoi tao queue that bai\n");
    }

    return 0;
}