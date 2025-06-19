#include<stdio.h>
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    int arr[n];

    for (int i=0;i<n;i++) {
        printf(" arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    int sumOfNumber;
    printf("Nhap tong: ");
    scanf("%d",&sumOfNumber);
    int count=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]+arr[j]==sumOfNumber) {
                printf("arr[%d]+arr[%d] = %d\n",i,j,arr[i]+arr[j]);
                count++;
            }
        }
    }
    if (count==0) {
        printf("Khong co so nao thoa man");
    }
    return 0;
}