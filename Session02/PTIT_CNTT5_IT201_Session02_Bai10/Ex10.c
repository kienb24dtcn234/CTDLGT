//
// Created by Cachiu on 17/6/25.
//
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
    int length=0;
    int unique[length];
    for (int i=0;i<n;i++) {
        int count=1;
        for (int j=i+1;j<n;j++) {
            if (unique[j]==arr[i]) {
                count++;
            }
        }
        if (count==1) {
            unique[length]=arr[i];

            length++;
        }
    }
    for (int i=0;i<length;i++) {
        int count=1;
        for (int j=i+1;j<n;j++) {
            if (arr[j]==unique[i]) {
                count++;
            }
        }
        printf("%d xuat hien %d\n", unique[i],count);
    }
    return 0;

}