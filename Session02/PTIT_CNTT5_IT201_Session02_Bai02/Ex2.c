#include <stdio.h>

int main() {
    int arr1[] = {1, 1, 2, 3, 9, 7, 2};
    int n1 = 7;
    int arr2[] = {1, 3, 4, 4, 1, 2, 2};
    int n2 = 7;
    int x, dem;
    printf("nhap so can dem: ");
    scanf("%d", &x);
    dem = 0;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] == x) {
            dem++;
        }
    }
    printf("%d\n", dem);
    dem = 0;
    for (int i = 0; i < n2; i++) {
        if (arr2[i] == x) {
            dem++;
        }
    }
    printf("%d\n", dem);
    return 0;
}

