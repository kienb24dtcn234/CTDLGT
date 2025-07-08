#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elements;
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

int isFull(Stack* stack) {
    return stack->top == stack->cap - 1;
}

void push(Stack* stack, int element) {
    if (isFull(stack)) return;
    stack->elements[++stack->top] = element;
}

int main() {
    int capacity = 5;
    Stack* stack = createStack(capacity);
    int element;

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < capacity; i++) {
        scanf("%d", &element);
        push(stack, element);
    }

    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i < capacity; i++) {
        printf("%d", stack->elements[i]);
        if (i < capacity - 1) {
            printf(", ");
        }
    }
    printf("],\n");
    printf("    top: %d,\n", stack->top);
    printf("    cap: %d\n", stack->cap);
    printf("}\n");

    free(stack->elements);
    free(stack);

    return 0;
}