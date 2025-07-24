#include <stdio.h>

int main() {
    int vertices, edges;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &vertices, &edges);
    int adjMatrix[100][100] = {0};
    printf("Nhap cac canh:\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int adjacentVertices = 0;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[k][i] == 1) {
            adjacentVertices++;
        }
    }
    printf("So dinh ke voi %d la: %d\n", k, adjacentVertices);
    return 0;
}