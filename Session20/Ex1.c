#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int data;
    printf("Nhap so nguyen: ");
    scanf("%d", &data);
    struct Node* node = createNode(data);
    printf("node = {\n");
    printf("    data: %d,\n", node->data);
    printf("    left->NULL,\n");
    printf("    right->NULL\n");
    printf("}\n");
    free(node);
    return 0;
}