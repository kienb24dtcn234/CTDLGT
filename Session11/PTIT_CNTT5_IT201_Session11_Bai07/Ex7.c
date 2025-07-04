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

void insertNode(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int i = 0;
    while (current != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
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

    struct Node* node1 = createNode(1);
    if (head == NULL) {
        head = node1;
        tail = node1;
    }

    struct Node* node2 = createNode(2);
    node1->next = node2;
    node2->prev = node1;
    tail = node2;

    struct Node* node3 = createNode(3);
    node2->next = node3;
    node3->prev = node2;
    tail = node3;

    struct Node* node4 = createNode(4);
    node3->next = node4;
    node4->prev = node3;
    tail = node4;

    struct Node* node5 = createNode(5);
    node4->next = node5;
    node5->prev = node4;
    tail = node5;

    printf("1<->2<->3<->4<->5->NULL\n");

    int value, position;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &position);

    insertNode(&head, value, position);

    printList(head);

    struct Node* current = head;
    while (current != NULL)
     {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}