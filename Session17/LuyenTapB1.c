#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    float price;
} Product;

typedef struct Node {
    Product data;
    struct Node *next;
} Node;

typedef struct DNode {
    Product data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

Node *head = NULL;
DNode *soldHead = NULL;

void addProduct()
{
Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Nhap Id : ");
    scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap Name :");
    fgets(newNode->data.name, 100, stdin);
    newNode->data.name[strcspn(newNode->data.name, "\n")] = '\0';
    printf("Nhap Float :");
    scanf("%f", &newNode->data.price);
    newNode->next = head;
    head = newNode;
    printf("==> Da them san pham thanh cong!\n");
}
void displayProducts()
{
    Node *p = head;
    if (!p)
    {
        printf("Danh sach rong !");
        return;
    }
    printf("\n--- Danh sach san pham dang co ---\n");
    while (p)
    {
        printf("ID: %d | Name : %s | Float : %.2f \n", p->data.id, p->data.name, p->data.price);
        p = p->next;
    }

}
void deleteProduct()
{
    int id;
    printf("Nhap ID san pham can xoa: ");
    scanf("%d", &id);
    Node *p = head, *prev = NULL;
    while (p && p->data.id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        printf("==> Khong tim thay san pham!\n");
        return;
    }
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("==> Da xoa san pham!\n");
}
void freeAll() {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
    DNode *q;
    while (soldHead) {
        q = soldHead;
        soldHead = soldHead->next;
        free(q);
    }
}
void updateProduct()
{
    int id;
    printf("Nhap ID san pham can cap nhat : ");
    scanf("%d", &id);
    Node *p = head;
    while (p && p-> data.id != id)
        p = p -> next;
    if (!p)
    {
        printf("Khong tim thay san pham! \n");
        return;
    }
    getchar();
    printf("Nhap Name : ");
    fgets(p -> data.name, 100, stdin);
    p -> data.name[strcspn(p -> data.name,"\n")] = '\0';
    printf("Nhap gia moi : ");
    scanf(("%f", &p -> data.price));
    printf(("Da cap nhat ! \n"));
}
int main() {
    int choice;
    do {
        printf("\n——————————— PRODUCT MANAGER ——————————\n");
        printf("Them san pham\n");
        printf("Hien thi danh sach san pham\n");
        printf("Xoa san pham theo id\n");
        printf("Cap nhat thong tin san pham\n");
        printf("Danh dau san pham da ban\n");
        printf("Hien thi danh sach san pham da ban\n");
        printf("Sap xep san pham theo gia tang dan (Bubble Sort)\n");
        printf("Tim kiem san pham theo ten (Linear Search)\n");
        printf("Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: deleteProduct(); break;
            case 4: updateProduct(); break;
            case 9: freeAll(); printf("==> Thoat chuong trinh!\n"); break;
            default: printf("==> Lua chon khong hop le!\n");
        }
    } while (choice != 9);
    return 0;
}