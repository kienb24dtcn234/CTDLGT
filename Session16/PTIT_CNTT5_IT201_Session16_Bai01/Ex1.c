#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 100

typedef struct Node {
    char name[NAME_MAX];
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Added: %s\n", name);
}

void peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front: %s\n", q->front->name);
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    Node* temp = q->front;
    printf("Removes: %s\n", temp->name);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = q->front;
    printf("Queue contents:\n");
    while (current != NULL) {
        printf(" - %s\n", current->name);
        current = current->next;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, "Anh");
    enqueue(&q, "Binh");
    enqueue(&q, "Cao");

    peek(&q);
    displayQueue(&q);

    dequeue(&q);
    peek(&q);
    displayQueue(&q);

    return 0;
}