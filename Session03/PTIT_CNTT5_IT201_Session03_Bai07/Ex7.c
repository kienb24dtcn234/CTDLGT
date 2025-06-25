#include <stdio.h>
#include <stdlib.h>

int tinhTongHang(int** arr, int rows, int cols, int k) {
    int tong = 0;
    if (k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai\n");
        return -1;
    }
    for (int j = 0; j < cols; j++) {
        tong += arr[k][j];
    }
    return tong;
}
int main() {
    int rows, cols, k, tongHangK;
    printf("rows = ");
    scanf("%d", &rows);
    printf("cols = ");
    scanf("%d", &cols);
    if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 0;
    }
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("k = ");
    scanf("%d", &k);
    tongHangK = tinhTongHang(arr, rows, cols, k);
    if (tongHangK != -1) {
        printf("sum = %d\n", tongHangK);
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}