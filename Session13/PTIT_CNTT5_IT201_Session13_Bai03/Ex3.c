#include <stdio.h>

typedef struct {
    int* elements;
    int top;
    int cap;
} Stack;

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = stack->elements[stack->top];
    stack->top--;
    return value;
}

int main() {
    Stack stack1 = {
        .elements = (int[]){10, 20, 30, 40, 50},
        .top = 4,
        .cap = 5
    };

    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= stack1.top; i++) {
        printf("%d", stack1.elements[i]);
        if (i < stack1.top) {
            printf(", ");
        }
    }
    printf("],\n");
    printf("    top: %d,\n", stack1.top);
    printf("    cap: %d\n", stack1.cap);
    printf("}\n");

    int popped_value1 = pop(&stack1);
    if (popped_value1 != -1) {
        printf("%d\n", popped_value1);
    }
    Stack stack2 = {
        .elements = (int[]){},
        .top = -1,
        .cap = 5
    };

    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= stack2.top; i++) {
        printf("%d", stack2.elements[i]);
        if (i < stack2.top) {
            printf(", ");
        }
    }
    printf("],\n");
    printf("    top: %d,\n", stack2.top);
    printf("    cap: %d\n", stack2.cap);
    printf("}\n");
    int popped_value2 = pop(&stack2);
    return 0;
}