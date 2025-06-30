#include <stdio.h>

void thapHaNoi(int n, char nguon, char trungGian, char dich) {
    if (n > 0) {
        thapHaNoi(n - 1, nguon, dich, trungGian);
        printf("Dia %d di chuyen tu %c sang %c\n", n, nguon, dich);
        thapHaNoi(n - 1, trungGian, nguon, dich);
    }
}
int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        thapHaNoi(n, 'A', 'B', 'C');
    }
    return 0;
}