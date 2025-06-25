#include <stdio.h>
#include <stdlib.h>

float TBsochan(int *arr, int n) {
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            tong += arr[i];
            dem++;
        }
    }
    if (dem == 0) {
        return 0;
    }
    return (float)tong / dem;
}
int main() {
    int i, n;
    int *arr;
    float trungbinhcong;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    trungbinhcong = TBsochan(arr, n);
    printf("Trung binh cong cac so chan trong mang la: %.2f\n", trungbinhcong);
    free(arr);
    return 0;
}