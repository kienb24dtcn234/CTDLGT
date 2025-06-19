#include <stdio.h>

void update_array(int arr[], int size, int pos, int val) {
    arr[pos] = val;
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int arr1[] = {-1, 5, -3, 2, 10};
    update_array(arr1, 5, 0, 3);

    int arr2[] = {1, 4, 2, 6, 10};
    update_array(arr2, 5, 2, 7);

    return 0;
}