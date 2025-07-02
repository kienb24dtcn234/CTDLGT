#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi: Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Danh sach lien ket ban dau:\n");
    printList(head);
    int new_element;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &new_element);
    push(&head, new_element);
    printf("Danh sach lien ket sau khi them %d vao dau:\n", new_element);
    printList(head);
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    return 0;
}