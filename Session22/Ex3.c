#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int n;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void convertMatrixToList(int matrix[100][100], int n, Graph* graph) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}

void printAdjList(Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Graph* graph = createGraph(n);
    convertMatrixToList(matrix, n, graph);
    printAdjList(graph);

    for (int i = 0; i < n; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}