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

int getLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");

    int length = getLength(head);
    printf("Danh sach lien ket co %d phan tu\n", length);

    return 0;
}