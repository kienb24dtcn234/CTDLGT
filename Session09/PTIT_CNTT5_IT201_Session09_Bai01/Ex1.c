#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* createNode (int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    struct Node* head = createNode(15);
    struct Node* second= createNode(25);
    struct Node* third = createNode(35);
    struct Node* fourth = createNode(45);
    struct Node* fifth = createNode(55);

    head->next = second;
    second->next = third;
    third->next= fourth;
    fourth->next = fifth;

    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
    current = head;
    while (current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
