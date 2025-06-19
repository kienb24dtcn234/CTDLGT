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
    int addIndex,newNumber;
    do {
        printf("Nhap chi so: ");
        scanf("%d",&addIndex);
        if (addIndex<0||addIndex>=n) {
            printf("Chi so khong hop le\n");
        }
    } while (addIndex<0||addIndex>=n);
    printf("Nhap so moi: ");
    scanf("%d", &newNumber);

    for (int j = n; j > addIndex; j--) {
        arr[j] = arr[j - 1];
    }

    arr[addIndex] = newNumber;
    n++;

    printf("Mang sau khi chen:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}