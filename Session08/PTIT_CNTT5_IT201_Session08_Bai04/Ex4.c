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

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            {
            if (arr[j] < arr[minIndex])
                {
                minIndex = j;
            }
        }
        if (minIndex != i)
            {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    printf("[ ");
    printArray(arr, n);
    printf("]\n");
    selectionSort(arr, n);
    printf("[ ");
    printArray(arr, n);
    printf("]\n");

    return 0;
}