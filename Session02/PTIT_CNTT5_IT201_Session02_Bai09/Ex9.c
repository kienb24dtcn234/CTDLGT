#include<stdio.h>
int main() {
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int arr[n];

    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int maxCount=1;
    for (int i=0;i<n;i++) {
        int count=0;
        for (int j=i+1;j<n;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }
        printf("count[%d] = %d\n",i,count);
        if (count>maxCount) {
            maxCount=count;
            max=arr[i];
        }
    }
    printf("so xuat hien nhieu nhat la : %d",max);
}