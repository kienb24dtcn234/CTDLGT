#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}
void traverseList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("data: %d\n", temp-> data);
        temp = temp -> next;
    }
}

int main()
{
    struct Node* head = NULL;
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 5);

    printList((head));
    traverseList(head);
    return 0;
}