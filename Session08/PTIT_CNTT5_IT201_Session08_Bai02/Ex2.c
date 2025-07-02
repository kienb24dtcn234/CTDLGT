#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int search)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            return mid;
        }
        if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        {
        for (int j = i + 1; j < size; j++)
            {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[1000];
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    sortArray(arr, n);
    printf("before = [ ");
    printArray(arr, n);
    printf("]\n");
    int search;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &search);
    int result = binarySearch(arr, n, search);
    if (result != -1) {
        printf("phan tu vi tri thu %d\n", result + 1);
    } else {
        printf("Khong ton tai phan tu\n");
    }
    return 0;
}