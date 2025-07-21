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

Node* addValue(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    Node** queue = (Node**)malloc(sizeof(Node*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(value);
            free(queue);
            return root;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            free(queue);
            return root;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

int main() {
    int data;
    printf("Nhap so nguyen cho nut goc: ");
    scanf("%d", &data);

    Node* root = createNode(data);

    printf("root = {\n");
    printf("    data: %d,\n", root->data);
    printf("    left->NULL,\n");
    printf("    right->NULL\n");
    printf("}\n");

    int valueToAdd;
    printf("Nhap gia tri can them: ");
    scanf("%d", &valueToAdd);

    root = addValue(root, valueToAdd);

    printf("Sau khi them %d:\n", valueToAdd);
    printf("root = {\n");
    printf("    data: %d,\n", root->data);
    if(root->left != NULL){
        printf("    left->data: %d,\n", root->left->data);
    } else {
        printf("    left->NULL,\n");
    }

    if(root->right != NULL){
        printf("    right->data: %d\n", root->right->data);
    } else {
         printf("    right->NULL\n");
    }
    printf("}\n");
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}