#include <stdio.h>

int MATRIX[3][3];
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
void addEdge(int U, int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}
void printMATRIX() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrix();
    printMATRIX();
    int firstNode = 0;
    int secondNode = 1;
    addEdge(firstNode, secondNode);
    printf("\n");
    printMATRIX();
    return 0;
}