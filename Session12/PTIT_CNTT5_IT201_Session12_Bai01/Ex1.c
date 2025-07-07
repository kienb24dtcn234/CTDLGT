#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* createDoublyLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node* head = createNode(1);
    struct Node* tail = head;

    for (int i = 2; i <= n; i++) {
        struct Node* newNode = createNode(i);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int main() {
    int n = 5;
    struct Node* head = createDoublyLinkedList(n);

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}