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

struct Node* createDoublyLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node* head = createNode(1);
    struct Node* tail = head;

    for (int i = 2; i <= n; i++) {
        struct Node* newNode = createNode(i);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        if (current->data == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            next = current->next;
            free(current);
            current = next;
        } else {
            current = current->next;
        }
    }
    return head;
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
    int n = 7;
    struct Node* head = createDoublyLinkedList(n);
    head = deleteNode(head, 2);
    struct Node* newNode1 = createNode(5);
    struct Node* newNode2 = createNode(4);
     struct Node* newNode3 = createNode(3);
    struct Node* newNode4 = createNode(5);
     struct Node* newNode5 = createNode(2);
    struct Node* newNode6 = createNode(1);
     struct Node* newNode7 = createNode(5);
     head = newNode1;
     newNode1->next=newNode2;
      newNode2->prev = newNode1;
      newNode2->next=newNode3;
       newNode3->prev = newNode2;
       newNode3->next=newNode4;
        newNode4->prev = newNode3;
        newNode4->next=newNode5;
         newNode5->prev = newNode4;
         newNode5->next=newNode6;
          newNode6->prev = newNode5;
          newNode6->next=newNode7;
           newNode7->prev = newNode6;
           newNode7->next=NULL;

    printf("5<->4<->3<->5<->2<->1<->5->NULL\n");

    int key;
    printf("5\n");
     key = 5;
    head = deleteNode(head, key);

    printList(head);

    return 0;
}