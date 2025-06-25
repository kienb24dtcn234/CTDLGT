#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    int *arr;
    int max;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    if (n < 0 || n > 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }
    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("So lon nhat trong mang la: %d\n", max);
    free(arr);
    return 0;
}