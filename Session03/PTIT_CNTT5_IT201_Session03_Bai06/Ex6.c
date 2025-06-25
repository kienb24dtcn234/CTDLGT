#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, i, j;
    int *arr;
    printf("n = ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("m = ");
    scanf("%d", &m);
    printf("\n");
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }
    for (i = n; i < n + m; i++) {
        if(i > 0) printf(", ");
        scanf("%d", &arr[i]);
    }
    printf("\n[ ");
    for (i = 0; i < n + m; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf(" ]\n");
    free(arr);
    return 0;
}