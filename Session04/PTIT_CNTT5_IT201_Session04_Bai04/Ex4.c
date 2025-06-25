#include <stdio.h>
int main() {
    int n, i, target, lastIndex = -1;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            lastIndex = i;
        }
    }
    if (lastIndex != -1) {
        printf("%d\n", lastIndex);
    } else {
        printf("Khong tim thay phan tu\n");
    }

    return 0;
}