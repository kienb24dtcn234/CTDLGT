#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

bool isPalindrome(char str[]) {
    Stack stack;
    initialize(&stack);
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        if (str[i] != pop(&stack)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char str[MAX_SIZE];
    printf("Nhap chuoi: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}