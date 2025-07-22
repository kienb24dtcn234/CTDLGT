#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max) {
        max = leftMax;
    }

    if (rightMax > max) {
        max = rightMax;
    }

    return max;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int maxValue = findMax(root);
    printf("max value: %d\n", maxValue);
    free(root->left->right);
    free(root->left->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}