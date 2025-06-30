#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}
void sortArray(int arr[], int size) {
    int left = 0, right = size - 1, mid = 0;
    while (mid <= right) {
        if (arr[mid] < 0) {
            int temp = arr[left];
            arr[left] = arr[mid];
            arr[mid] = temp;
            left++;
            mid++;
        } else if (arr[mid] > 0) {
            int temp = arr[right];
            arr[right] = arr[mid];
            arr[mid] = temp;
            right--;
        } else {
            mid++;
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[n];
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("before = [ ");
    printArray(arr, n);
    printf("]\n");
    sortArray(arr, n);
    printf("after = [ ");
    printArray(arr, n);
    printf("]\n");
    return 0;
}