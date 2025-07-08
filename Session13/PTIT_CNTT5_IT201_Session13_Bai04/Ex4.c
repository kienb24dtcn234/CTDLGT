#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = capacity;
    stack->top = -1;
    stack->elements = (int*)malloc(stack->cap * sizeof(int));
    return stack;
}

void push(Stack* stack, int data) {
    if (stack->top == stack->cap - 1) return;
    stack->elements[++stack->top] = data;
}

int pop(Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->elements[stack->top--];
}

void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->elements[i]);
    }
}

int main() {
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    printf("stack={\n");
    printf("    elements: [");
    for(int i = 0; i < 4; i++){
        printf("%d, ", stack->elements[i]);
    }
    printf("%d],\n", stack->elements[4]);
    printf("    top: %d,\n", stack->top);
    printf("    cap: %d\n", stack->cap);
    printf("}\n");

    printStack(stack);

    free(stack->elements);
    free(stack);

    return 0;
}