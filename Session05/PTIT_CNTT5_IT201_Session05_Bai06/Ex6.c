#include <stdio.h>

int tinhTongMang(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return arr[n - 1] + tinhTongMang(arr, n - 1);
    }
}
int main() {
    int n, i;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int tong = tinhTongMang(arr, n);
    printf("Tong cua mang la: %d\n", tong);
    return 0;
}