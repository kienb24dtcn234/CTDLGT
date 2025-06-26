#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int* fibonacciArray(int n) {
    if (n <= 0) {
        return NULL;
    }
    int* result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Lỗi cấp phát bộ nhớ!");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        result[i] = fibonacci(i);
    }
    return result;
}
int main() {
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }
    int* fibArray = fibonacciArray(n);
    if (fibArray != NULL) {
        for (int i = 0; i < n; i++) {
            printf("%d", fibArray[i]);
            if (i < n - 1) {
                printf(",");
            }
        }
        printf("\n");
        free(fibArray);
    }
    return 0;
}