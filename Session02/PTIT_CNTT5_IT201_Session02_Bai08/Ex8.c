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
    int new[n];
    int index=0;
    new[index]=arr[n-1];
    index++;
    int min=arr[n-1];
    for (int i=n-2;i>=0;i--) {
        if (arr[i]>min) {
            min=arr[i];
            new[index]=arr[i];
            index++;
        }
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", new[i]);
    }

    return 0;
}