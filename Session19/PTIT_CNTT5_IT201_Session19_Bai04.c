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

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\n", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = createNode(5);
    root->left = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(4);

    printf("Inorder traversal:\n");
    inorderTraversal(root);
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}