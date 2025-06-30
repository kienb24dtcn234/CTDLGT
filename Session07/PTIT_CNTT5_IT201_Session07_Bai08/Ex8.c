#include <stdio.h>

void printMatrix(int matrix[][1000], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(" ");
        }
        printf("\n");
    }
}

void sortColumn(int matrix[][1000], int rows, int k) {
    int temp[1000];
    for (int i = 0; i < rows; i++) {
        temp[i] = matrix[i][k];
    }
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        matrix[i][k] = temp[i];
    }
}

int main() {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So hang hoac so cot khong hop le\n");
        return 0;
    }

    int matrix[1000][1000];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu hang %d cot %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int k;
    printf("Nhap so cot can sap xep (k): ");
    scanf("%d", &k);
    if (k < 0 || k >= cols) {
        printf("So cot khong hop le\n");
        return 0;
    }

    printf("before:\n");
    printMatrix(matrix, rows, cols);

    sortColumn(matrix, rows, k);

    printf("after:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}