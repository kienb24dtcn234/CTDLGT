#include <stdio.h>
int linearSearch(int arr[], int n, int search)
{
    for ( int i = 0; i < n ; i ++)
    {
        if ( arr[i]== search)
        {
            return 1;
        }
    }
    return -1;
}
int main()
{
    int n, search;
    printf("Nhap so luong phan tu cua mang(0 < n < 1000): ");
    scanf("%d", &n);
    if ( n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le \n");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim : ");
    scanf("%d", &search);
    int position = linearSearch(arr, n , search);
    if (position != -1)
    {
        printf("Vi tri thu %d\n", position + 1);
    }else
    {
        printf("Khong ton tai phan tu \n");
    }
    return 0;
}