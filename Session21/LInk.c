#include <stdio.h>
typedef  struct Node
{
    int data;
    struct Node* next;
}Node;
// Viết hàm tạo Node
Node* createNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    newNode-> data = value;
    newNode-> next = NULL;
    return newNode;
}
// Tạo mảng chứa danh sách các con trỏ trỏ tới từng

// Viết hàm tạo liên kết
Node *createAdjacency( int U, int V)
{
    // Tạo 1 nốt mới , thêm vào đầu
    Node% newNode = createNode(U);
    // đi liên kết với phần tử ban đầu
    newNode-> next = createNode(U);
    newNode = createNode(U);// NewNode lúc mày sẽ là phần tử đầu
    newNode = createNode(V);
    newNode->next= createNode(V);// Liên kết với phần tử ban đầu
    newNode = createNode(V);// NewNode bây giờ sẽ thành phần tử đầu tiên
    Node* newNode = createNode(V);
    newNode->next = adjacency(V); // Liên kết với phần tử ban đầu
    newNode = adjacency(V);
}

void printAdjacency()
{
    for (int i = 1; i < 4; i++)
    {
        Node* current = adjacency[i];
        while (current != NULL)
        {
            printf("%d", current->data);
            current = current->next;
        }
    }
}

Node* adjacency[4];
int main()
{
    // Khởi tạo các giá tri trong mảng về NULL
    for ( int i =1; i <= 4; i++)
    {
        adjacency[i] = NULL;
    }
}