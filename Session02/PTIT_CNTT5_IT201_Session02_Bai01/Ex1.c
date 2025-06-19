#include <stdio.h>
int main() {
    int n = 6;
    int arr1[] = {-1, 5, -3, 2, 10, 19};
    int max = arr1[0];
    for (int i = 1; i < n; i++) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }
    printf("%d\n", max);
    return 0;
}
