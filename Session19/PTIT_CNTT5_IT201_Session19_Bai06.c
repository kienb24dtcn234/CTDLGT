#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool breadthFirstSearch(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    Node* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->data == target) {
            return true;
        }

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    return false;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int findValue;
    printf("findValue: ");
    scanf("%d", &findValue);

    if (breadthFirstSearch(root, findValue)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);


    return 0;
}