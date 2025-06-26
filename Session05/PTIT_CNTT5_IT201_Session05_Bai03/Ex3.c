#include <stdio.h>
long long fatorial(int n){
    if (n < 0){
        return -1;
    }else if (n == 0)
    {
        return 1;
    }else
    {
        return n * fatorial (n-1);
    }
}
int main()
{
    int num;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &num);
    long long result = fatorial(num);
    if (result == -1)
    {
        printf("Khong hop le\n");
    }else
    {
        printf("%11d\n", result);
    }
    return 0;
}