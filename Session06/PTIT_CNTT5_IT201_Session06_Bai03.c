#include <stdio.h>
int sumDigits(int n)
{
    if (n < 0)
    {
        printf("Nhap vao khong hop le ");
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    return (n%10) + sumDigits(n/10);
}
int main()
{
    int n;
    printf("Nhap vao so nguyen duong n :");
    scanf("%d", &n);
    int sum = sumDigits(n);
    if (sum != -1)
    {
        printf("%d\n", sum);
    }
    return 0;
}