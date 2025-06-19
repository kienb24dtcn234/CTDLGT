#include <stdio.h>

void delete_element(int arr[], int *length, int pos) {
    for (int i = pos; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
    printf("[");
    for (int i = 0; i < *length; i++) {
        printf("%d", arr[i]);
        if (i < *length - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int arr1[] = {-1, 5, -3, 2, 10};
    int length1 = 5;
    delete_element(arr1, &length1, 2);

    int arr2[] = {1, 4, 2, 6, 10};
    int length2 = 5;
    delete_element(arr2, &length2, 6);

    return 0;
}