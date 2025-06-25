#include <stdio.h>
int main() {
    int n, i, search_value;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search_value);
    int found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == search_value) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Phan tu khong co trong mang");
    }
    printf("\n");
    return 0;
}