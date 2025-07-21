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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int main() {
    int data;
    printf("Nhap so nguyen: ");
    scanf("%d", &data);

    Node* root = createNode(data);
    root->left = createNode(data + 1);
    root->right = createNode(data + 2);
    root->left->left = createNode(data + 3);

    printf("node = {\n");
    printf("    data: %d,\n", root->data);
    printf("    left->data: %d,\n", root->left->data);
    printf("    right->data: %d\n", root->right->data);
    printf("}\n");

    printf("Chieu cao cua cay la: %d\n", height(root));


    return 0;
}