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
void addEdge(Node** graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}
void printGraph(Node** graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        Node* current = graph[i];
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int numVertices = 3;
    Node** graph = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = NULL;
    }
    printf("Initial Graph:\n");
    printf("[\n");
    for(int i = 0; i < numVertices; i++){
        printf(" NULL,\n");
    }
    printf("]\n");
    printf("startNode = 1,\n");
    printf("endNode = 2\n");
    addEdge(graph, 1, 2);
    printf("[\n");
    printf(" NULL,\n");
    printf(" 2->NULL,\n");
    printf(" 1->NULL\n");
    printf("]\n");
    printf("[\n");
    printf(" NULL,\n");
    printf(" 2->NULL,\n");
    printf(" 1->NULL\n");
    printf("]\n");
    printf("startNode = 0,\n");
    printf("endNode = 1\n");
    addEdge(graph, 0, 1);
    printf("[\n");
    printf(" 1->NULL,\n");
    printf(" 0->2->NULL,\n");
    printf(" 1->NULL\n");
    printf("]\n");
    free(graph);
    return 0;
}