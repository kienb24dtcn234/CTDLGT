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

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\n", root->data);
    }
}

int main() {
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(2);

    printf("Duyet cay hau thu tu:\n");
    postorderTraversal(root);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}