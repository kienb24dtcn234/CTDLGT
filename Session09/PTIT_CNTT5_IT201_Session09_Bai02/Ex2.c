#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node ;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    int node_number = 1;
    while (temp != NULL) {
        printf("Node %d: %d\n", node_number, temp->data);
        temp = temp->next;
        node_number++;
    }
}

int main()
{
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printList(head);
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    return 0;
}