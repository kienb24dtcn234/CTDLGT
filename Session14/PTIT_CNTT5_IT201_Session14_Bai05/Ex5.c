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

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    struct Stack* stack = createStack();
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    stack->top = node1;

    printf("%d\n", peek(stack));

    struct Stack* emptyStack = createStack();
    peek(emptyStack);

    return 0;
}