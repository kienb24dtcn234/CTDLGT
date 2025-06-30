#include <stdio.h>
void decimalTobinary(int n)
{
    if (n >0)
    {
        decimalTobinary(n / 2);
        printf("%d", n % 2);
    }
}
int main()
{
    int num;
    printf("Nhap vao mot so nguyen duong: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Vui long nhap vao mot so nguyen duong");
        return 1;
    }
    printf("Dang nhi phan : ");
    if (num == 0)
    {
        printf("0");
    }else
    {
        decimalTobinary(num);
    }
     printf("\n");
    return 0;
}