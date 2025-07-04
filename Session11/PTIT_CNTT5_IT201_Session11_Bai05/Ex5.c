#include <stdio.h>
#include <stdlib.h>

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

void insertAtBeginning(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    insertAtBeginning(&head, &tail, 5);
    insertAtBeginning(&head, &tail, 4);
    insertAtBeginning(&head, &tail, 3);
    insertAtBeginning(&head, &tail, 2);
    insertAtBeginning(&head, &tail, 1);

    printList(head);

    int newData;
    printf("Nhap vao so nguyen duong bat ky: ");
    scanf("%d", &newData);

    insertAtBeginning(&head, &tail, newData);

    printList(head);

    return 0;
}