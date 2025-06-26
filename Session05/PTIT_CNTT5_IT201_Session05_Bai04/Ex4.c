#include <stdio.h>
int tinhTong(int firstNum, int secondNum) {
    if (firstNum > secondNum) {
        return 0;
    } else {
        return firstNum + tinhTong(firstNum + 1, secondNum);
    }
}
int main() {
    int firstNum, secondNum;
    printf("Nhap vao hai so nguyen duong firstNum va secondNum, cach nhau bang dau phay: ");
    scanf("%d, %d", &firstNum, &secondNum);
    if (firstNum <= 0 || secondNum <= 0) {
        printf("Khong hop le\n");
    } else {
        int tong = tinhTong(firstNum, secondNum);
        printf("%d\n", tong);
    }
    return 0;
}
