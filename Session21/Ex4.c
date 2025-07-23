#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v, int adjacency[][3]) {
    adjacency[u][v] = 1;
    adjacency[v][u] = 1;
}

void printMatrix(int adjacency[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d, ", adjacency[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int adjacency[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            adjacency[i][j] = 0;
        }
    }
    printf("[\n");
    printMatrix(adjacency);
    printf("]\n");
    addEdge(1, 0, adjacency);
    addEdge(1, 2, adjacency);
    addEdge(2, 0, adjacency);
    printf("[\n");
    printMatrix(adjacency);
    printf("]\n");
    return 0;
}