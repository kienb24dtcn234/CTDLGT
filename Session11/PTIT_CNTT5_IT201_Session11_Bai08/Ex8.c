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

void deleteNode(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* current = *head;
    int i;

    if (position == 0) {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return;
    }

    for (i = 0; current != NULL && i < position; i++)
        current = current->next;

    if (current == NULL) return;

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf("<->");
        }
        node = node->next;
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
    int position;
    printf("Nhap vao vi tri muon xoa: ");
    scanf("%d", &position);

    deleteNode(&head, position);
    printList(head);

    return 0;
}