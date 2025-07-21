#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int data;
    printf("Nhap so nguyen: ");
    scanf("%d", &data);

    Node* node = createNode(data);

    printf("node = {\n");
    printf("    data: %d,\n", node->data);
    printf("    left->NULL,\n");
    printf("    right->NULL\n");
    printf("}\n");

    free(node);
    return 0;
}