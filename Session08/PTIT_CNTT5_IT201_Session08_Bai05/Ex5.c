#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    printf("[ ");
    printArray(arr, n);
    printf("]\n");
    insertionSort(arr, n);
    printf("[ ");
    printArray(arr, n);
    printf("]\n");

    return 0;
}