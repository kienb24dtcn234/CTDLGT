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

struct Node* findMiddleNode(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    int n1 = 5;
    struct Node* head1 = createDoublyLinkedList(n1);

    struct Node* current1 = head1;
    while (current1 != NULL) {
        printf("%d", current1->data);
        if (current1->next != NULL){
            printf("<->");
        }
        else{
            printf("->NULL");
        }
        current1 = current1->next;
    }
    printf("\n");

    struct Node* middleNode1 = findMiddleNode(head1);
    printf("Node %d: %d\n", (n1+1)/2, middleNode1->data);

    int n2 = 6;
    struct Node* head2 = createDoublyLinkedList(n2);

    struct Node* current2 = head2;
    while (current2 != NULL) {
        printf("%d", current2->data);
        if (current2->next != NULL){
            printf("<->");
        }
        else{
            printf("->NULL");
        }
        current2 = current2->next;
    }
    printf("\n");

    struct Node* middleNode2 = findMiddleNode(head2);
    printf("Node %d: %d\n", (n2+1)/2, middleNode2->data);
    free(head1);
    free(head2);

    return 0;
}