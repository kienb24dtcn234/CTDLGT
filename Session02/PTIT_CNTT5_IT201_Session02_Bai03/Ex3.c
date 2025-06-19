#include <stdio.h>

int main() {
    int array1[] = {-1, 5, -3, 2, 10, 19};
    int size1 = 6;
    int array2[] = {1, 4, 2, 6, 10, 15};
    int size2 = 6;
    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    for (int i = size2 - 1; i >= 0; i--) {
        printf("%d ", array2[i]);
    }
    return 0;
}
