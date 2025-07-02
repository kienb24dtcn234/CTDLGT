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
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        {
        for (int j = 0; j < size - i - 1; j++)
            {
            if (arr[j] > arr[j + 1])
                {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
    printf("[ ");
    printArray(arr, n);
    printf("]\n");
    bubbleSort(arr, n);
    printf("[ ");
    printArray(arr, n);
    printf("]\n");

    return 0;
}