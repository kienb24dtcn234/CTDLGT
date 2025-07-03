#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            current = (prev == NULL) ? *head : prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    printf("5->4->3->5->2->1->5->NULL\n");

    int key;
    printf("5\n");
    key = 5;

    deleteNode(&head, key);

    printList(head);

    struct Node* current = head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;

    return 0;
}