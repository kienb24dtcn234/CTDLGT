#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* arr;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

void reverseArray(int arr[], int size) {
    struct Stack* stack = createStack(size);

    for (int i = 0; i < size; i++) {
        push(stack, arr[i]);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = pop(stack);
    }
    free(stack->arr);
    free(stack);
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");


    free(arr);

    return 0;
}