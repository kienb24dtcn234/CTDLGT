#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void inFibonacciNguoc(int n) {
    if (n <= 0) {
        printf("Input khong hop le");
        return;
    }

    for (int i = n; i >= 1; i--) {
        printf("%d", fibonacci(i));
        if (i > 1) {
            printf(", ");
        }
    }
}

int main() {
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);

    inFibonacciNguoc(n);

    return 0;
}