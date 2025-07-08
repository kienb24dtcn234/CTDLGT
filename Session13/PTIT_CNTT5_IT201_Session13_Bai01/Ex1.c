#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    unsigned capacity;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int main() {
    Stack* stack = createStack(5);
    if (stack) {
        printf("Stack created with capacity: %u\n", stack->capacity);
        free(stack->arr);
        free(stack);
    }
    return 0;
}