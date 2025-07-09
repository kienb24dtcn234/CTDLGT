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

int pop(struct Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int main() {
    struct Stack* stack = createStack();

    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);

    node1->next = stack->top;
    stack->top = node1;

    node2->next = stack->top;
    stack->top = node2;

    node3->next = stack->top;
    stack->top = node3;

    int popped_value = pop(stack);
    if (popped_value != -1) {
        printf("Giá trị lấy ra: %d\n", popped_value);
    }

    popped_value = pop(stack);
    if (popped_value != -1) {
        printf("Giá trị lấy ra: %d\n", popped_value);
    }

    popped_value = pop(stack);
    if (popped_value != -1) {
        printf("Giá trị lấy ra: %d\n", popped_value);
    }
    popped_value = pop(stack);

    free(stack); //free stack
    return 0;
}