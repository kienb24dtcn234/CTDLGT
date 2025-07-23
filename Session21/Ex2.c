#include <stdio.h>

int MATRIX[4][4];
int matrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            MATRIX[i][j] = 0;
        }
    }
    return 0;
}
void adjacency(int U, int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}
void printMATRIX() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrix();
    printMATRIX();
    adjacency(0, 1);
    adjacency(0, 2);
    adjacency(1, 2);
    adjacency(2, 3);
    printf("\n");
    printMATRIX();
    return 0;
}