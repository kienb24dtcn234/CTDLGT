#include <stdio.h>
int main() {
    int n, i;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong co phan tu doi xung\n");
        return 0;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Cac cap doi xung:\n");
    int found = 0;
    for (i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - 1 - i]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - 1 - i]);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Khong co phan tu doi xung\n");
    }
    return 0;
}