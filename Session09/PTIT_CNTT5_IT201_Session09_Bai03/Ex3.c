#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}
bool search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf("->");
        }
        node = node->next;
    }
    printf("->NULL\n");
}

int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printf("Danh sach lien ket:\n");
    printList(head);
    int key;
    printf("Nhap vao so nguyen duong bat ky: ");
    scanf("%d", &key);
    if (search(head, key)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    return 0;
}