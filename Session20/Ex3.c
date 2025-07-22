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
struct Node* addValue(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = createNode(data);
            return root;
        } else {
            queue[rear++] = current->left;
        }
        if (current->right == NULL) {
            current->right = createNode(data);
            return root;
        } else {
            queue[rear++] = current->right;
        }
    }
    return root;
}
void printTree(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    int data, valueToAdd;
    printf("Nhap so nguyen cho node goc: ");
    scanf("%d", &data);
    struct Node* root = createNode(data);
    printf("Nhap gia tri can them: ");
    scanf("%d", &valueToAdd);
    root = addValue(root, valueToAdd);
    printf("Nhap gia tri can them: ");
    scanf("%d", &valueToAdd);
    root = addValue(root, valueToAdd);
    printf("Cay sau khi them: ");
    printTree(root);
    printf("\n");

    return 0;
}