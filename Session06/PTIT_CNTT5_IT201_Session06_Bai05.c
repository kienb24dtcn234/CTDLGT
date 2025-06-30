#include <stdio.h>
int findMax(int arr[], int start, int end, int max) {
    if (start > end) {
        return max;
    }
    if (arr[start] > max) {
        max = arr[start];
    }
    return findMax(arr, start + 1, end, max);
}
int findMin(int arr[], int start, int end, int min) {
    if (start > end) {
        return min;
    }
    if (arr[start] < min) {
        min = arr[start];
    }
    return findMin(arr, start + 1, end, min);
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    max = findMax(arr, 0, n - 1, max);
    min = findMin(arr, 0, n - 1, min);
    printf("%d, %d", min, max);
    return 0;
}