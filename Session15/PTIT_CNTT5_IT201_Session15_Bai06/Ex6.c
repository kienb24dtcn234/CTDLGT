#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

bool checkIncreasing(Queue* q) {
    if (isEmpty(q) || q->front == q->rear) {
        return true;
    }
    int prev = dequeue(q);
    while (!isEmpty(q)) {
        int curr = dequeue(q);
        if (curr != prev + 1) {
            return false;
        }
        prev = curr;
    }
    return true;
}

int main() {
    int n, num;
    scanf("%d", &n);

    Queue* queue = createQueue();
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        enqueue(queue, num);
    }

    if (checkIncreasing(queue)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    free(queue);
    return 0;
}