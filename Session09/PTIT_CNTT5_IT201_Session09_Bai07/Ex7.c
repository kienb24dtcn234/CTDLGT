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

void insertNodeAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
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
    current->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Danh sach lien ket ban dau:\n");
    printList(head);

    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them: ");
    scanf("%d", &position);

    insertNodeAtPosition(&head, value, position);

    printf("Danh sach lien ket sau khi them:\n");
    printList(head);

    return 0;
}