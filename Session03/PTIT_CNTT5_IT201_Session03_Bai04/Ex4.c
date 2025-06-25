#include <stdio.h>
#include <stdlib.h>
int main() {
    int rows, cols;
    printf("Nhap so luong hang (0 < rows < 1000): ");
    scanf("%d", &rows);
    if (rows <= 0 || rows >= 1000) {
        printf("So luong hang khong hop le.\n");
        return 1;
    }
    printf("Nhap so luong cot (0 < cols < 1000): ");
    scanf("%d", &cols);
    if (cols <= 0 || cols >= 1000) {
        printf("So luong cot khong hop le.\n");
        return 1;
    }

    int arr[rows][cols];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("\n gia tri arr[%d][%d]",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    int max=arr[0][0];
    int min=arr[0][0];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(arr[i][j]>max) {
                max=arr[i][j];
            }else if (arr[i][j]<min) {
                min=arr[i][j];
            }
        }
    }
    printf("\nmax : %d",max);
    printf("\nmin : %d",min);
    return 0;
}