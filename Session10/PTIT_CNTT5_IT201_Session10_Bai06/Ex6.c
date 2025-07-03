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

struct Node* findMiddleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    struct Node* head1 = createNode(5);
    head1->next = createNode(4);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(2);
    head1->next->next->next->next = createNode(1);

    struct Node* middle1 = findMiddleNode(head1);
    printf("Node 3: %d\n", middle1->data);

    struct Node* head2 = createNode(5);
    head2->next = createNode(4);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(2);
    head2->next->next->next->next = createNode(1);
    head2->next->next->next->next->next = createNode(6);

    struct Node* middle2 = findMiddleNode(head2);
    printf("Node 4: %d\n", middle2->data);

    return 0;
}