#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

bool isValid(char* expression) {
    int length = strlen(expression);
    Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                return false;
            }

            char top = pop(stack);
            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == ']' && top != '[') ||
                (expression[i] == '}' && top != '{')) {
                return false;
                }
        }
    }

    return isEmpty(stack);
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;

    if (isValid(expression)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}