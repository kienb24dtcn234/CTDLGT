#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;                  // Mã chuyến đi
    char destination[100];   // Điểm đến
    char startDate[20];      // Ngày khởi hành (dd/mm/yyyy)
    int duration;            // Thời lượng chuyến đi (số ngày)
} Trip;

typedef struct Node {
    Trip data;
    struct Node *next;
} Node;

typedef struct DNode {
    Trip data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

Node *head = NULL;
DNode *completedHead = NULL;

void addTrip() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Nhap ID: "); scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap diem den: "); fgets(newNode->data.destination, 100, stdin);
    newNode->data.destination[strcspn(newNode->data.destination, "\n")] = '\0';
    printf("Nhap ngay khoi hanh (dd/mm/yyyy): "); fgets(newNode->data.startDate, 20, stdin);
    newNode->data.startDate[strcspn(newNode->data.startDate, "\n")] = '\0';
    printf("Nhap thoi luong (ngay): "); scanf("%d", &newNode->data.duration);
    newNode->next = head;
    head = newNode;
    printf("==> Da them chuyen di thanh cong!\n");
}

void displayTrips() {
    Node *p = head;
    if (!p) {
        printf("==> Danh sach rong!\n");
        return;
    }
    printf("\n--- Danh sach chuyen di sap toi ---\n");
    while (p) {
        printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi luong: %d\n",
               p->data.id, p->data.destination, p->data.startDate, p->data.duration);
        p = p->next;
    }
}

void deleteTrip() {
    int id;
    printf("Nhap ID chuyen di can xoa: ");
    scanf("%d", &id);
    Node *p = head, *prev = NULL;
    while (p && p->data.id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        printf("==> Khong tim thay chuyen di!\n");
        return;
    }
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("==> Da xoa chuyen di!\n");
}

void updateTrip() {
    int id;
    printf("Nhap ID chuyen di can cap nhat: ");
    scanf("%d", &id);
    Node *p = head;
    while (p && p->data.id != id)
        p = p->next;
    if (!p) {
        printf("==> Khong tim thay chuyen di!\n");
        return;
    }
    getchar();
    printf("Nhap diem den moi: "); fgets(p->data.destination, 100, stdin);
    p->data.destination[strcspn(p->data.destination, "\n")] = '\0';
    printf("Nhap ngay khoi hanh moi (dd/mm/yyyy): "); fgets(p->data.startDate, 20, stdin);
    p->data.startDate[strcspn(p->data.startDate, "\n")] = '\0';
    printf("Nhap thoi luong moi (ngay): "); scanf("%d", &p->data.duration);
    printf("==> Da cap nhat!\n");
}

void markCompleted() {
    int id;
    printf("Nhap ID chuyen di da hoan thanh: ");
    scanf("%d", &id);
    Node *p = head, *prev = NULL;
    while (p && p->data.id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        printf("==> Khong tim thay chuyen di!\n");
        return;
    }
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = p->data;
    newNode->prev = NULL;
    newNode->next = completedHead;
    if (completedHead) completedHead->prev = newNode;
    completedHead = newNode;
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("==> Da danh dau hoan thanh!\n");
}

void bubbleSortTrips() {
    if (!head || !head->next) return;
    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            // So sánh ngày khởi hành (dựa trên chuỗi ngày)
            if (strcmp(i->data.startDate, j->data.startDate) > 0) {
                Trip temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("==> Da sap xep theo ngay khoi hanh tang dan!\n");
}

void searchByDestination() {
    char keyword[100];
    getchar();
    printf("Nhap diem den can tim: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    Node *p = head;
    int found = 0;
    while (p) {
        if (strstr(p->data.destination, keyword)) {
            printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi luong: %d\n",
                   p->data.id, p->data.destination, p->data.startDate, p->data.duration);
            found = 1;
        }
        p = p->next;
    }
    if (!found)
        printf("==> Khong tim thay chuyen di!\n");
}

void displayCompletedTrips() {
    DNode *p = completedHead;
    if (!p) {
        printf("==> Chua co chuyen di nao hoan thanh!\n");
        return;
    }
    printf("\n--- Danh sach chuyen di da hoan thanh ---\n");
    while (p) {
        printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi luong: %d\n",
               p->data.id, p->data.destination, p->data.startDate, p->data.duration);
        p = p->next;
    }
}

void freeAll() {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
    DNode *q;
    while (completedHead) {
        q = completedHead;
        completedHead = completedHead->next;
        free(q);
    }
}

int main() {
    int choice;
    do {
        printf("\n————————— TRIP MANAGER —————————\n");
        printf("1. Them chuyen di moi\n");
        printf("2. Hien thi danh sach chuyen di\n");
        printf("3. Xoa chuyen di\n");
        printf("4. Cap nhat thong tin chuyen di\n");
        printf("5. Danh dau chuyen di da hoan thanh\n");
        printf("6. Sap xep chuyen di theo ngay khoi hanh\n");
        printf("7. Tim kiem chuyen di theo diem den\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTrip(); break;
            case 2: displayTrips(); break;
            case 3: deleteTrip(); break;
            case 4: updateTrip(); break;
            case 5: markCompleted(); break;
            case 6: bubbleSortTrips(); break;
            case 7: searchByDestination(); break;
            case 8: freeAll(); printf("==> Thoat chuong trinh!\n"); break;
            default: printf("==> Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}