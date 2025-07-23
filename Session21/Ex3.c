#include <stdio.h>

int MATRIX[3][3];
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
void addEdge(int graph[3][3], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
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
    int startNode = 1;
    int endNode = 2;
    addEdge(MATRIX, startNode, endNode);
    printf("\n");
    printMATRIX();
    return 0;
}