#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
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

bool searchList(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int initialData[] = {1, 2, 3, 4, 5};
    int numElements = sizeof(initialData) / sizeof(initialData[0]);

    for (int i = 0; i < numElements; i++) {
        struct Node* newNode = createNode(initialData[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");

    int searchKey;
    printf("Enter a positive integer to search: ");
    scanf("%d", &searchKey);

    if (searchList(head, searchKey)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
    tail = NULL;

    return 0;
}