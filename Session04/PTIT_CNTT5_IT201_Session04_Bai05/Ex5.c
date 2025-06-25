#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return 1;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}

int main() {
    int n, x;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == 1) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }
    return 0;
}