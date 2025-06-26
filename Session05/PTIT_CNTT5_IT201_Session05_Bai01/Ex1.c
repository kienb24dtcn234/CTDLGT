#include <stdio.h>

void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n - 1);
        printf("%d ", n);
    }
}

int main() {
    int n;

    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);

    printf("Cac so tu 1 den %d la: ", n);
    printNumbers(n);
    printf("\n");

    return 0;
}