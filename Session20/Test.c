#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node cho danh sách liên kết
struct Node {
    int data;
    struct Node* next;
};

//Khởi tạo danh sách rỗng
struct Node* khoiTaoDanhSach() {
    return NULL;
}

//Thêm một nút mới với giá trị nhị phân
struct Node* themNodeMoi(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Tạo danh sách mới
void taoDanhSachMoi(struct Node** head) {
    *head = NULL;
}

//Thêm các nút nhị phân
void themTatCaNut(struct Node** head) {
    *head = themNodeMoi(*head, 0); // Thêm 0
    *head = themNodeMoi(*head, 1); // Thêm 1
    *head = themNodeMoi(*head, 0); // Thêm 0
}

//Duyệt và in danh sách nhị phân
void duyetDanhSach(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = khoiTaoDanhSach();
    themTatCaNut(&head);
    printf("Danh sach nhi phan: ");
    duyetDanhSach(head);
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}