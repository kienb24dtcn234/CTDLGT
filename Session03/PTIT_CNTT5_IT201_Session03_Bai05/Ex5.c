#include <stdio.h>
#include <stdlib.h>

int tinhTongDuongCheoChinh(int** arr, int rows, int cols) {
    int tong = 0;
    if (rows != cols) return 0;
    for (int i = 0; i < rows; i++) {
        tong += arr[i][i];
    }
    return tong;
}

int tinhTongDuongCheoPhu(int** arr, int rows, int cols) {
    int tong = 0;
    if (rows <= 0 || cols <= 0 || rows != cols) return 0;
    for (int i = 0; i < rows; i++) {
        tong += arr[i][rows - 1 - i];
    }
    return tong;
}

int main() {
    int rows, cols;
    printf("Nhap so luong hang (0 < rows < 1000): ");
    scanf("%d", &rows);
    printf("Nhap so luong cot (0 < cols < 1000): ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("Kich thuoc khong hop le!\n");
        return 0;
    }
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int tongCheoChinh = tinhTongDuongCheoChinh(arr, rows, cols);
    int tongCheoPhu = tinhTongDuongCheoPhu(arr, rows, cols);
    printf("\nMa tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if (rows == cols) {
        printf("Tong duong cheo chinh = %d\n", tongCheoChinh);
        printf("Tong duong cheo phu = %d\n", tongCheoPhu);
    } else {
        printf("Khong ton tai duong cheo (khong phai ma tran vuong)\n");
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
