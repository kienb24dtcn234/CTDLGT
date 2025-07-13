#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    int credit;
} Course;

typedef struct Node {
    Course data;
    struct Node *next;
} Node;

typedef struct DNode {
    Course data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

Node *head = NULL;
DNode *completedHead = NULL;

void addCourse() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Nhap ID: "); scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap ten khoa hoc: "); fgets(newNode->data.title, 100, stdin);
    newNode->data.title[strcspn(newNode->data.title, "\n")] = '\0';
    printf("Nhap so tin chi: "); scanf("%d", &newNode->data.credit);
    newNode->next = head;
    head = newNode;
    printf("==> Da them khoa hoc thanh cong!\n");
}

void displayCourses() {
    Node *p = head;
    if (!p) {
        printf("==> Danh sach rong!\n");
        return;
    }
    printf("\n--- Danh sach khoa hoc dang hoc ---\n");
    while (p) {
        printf("ID: %d | Ten: %s | Tin chi: %d\n", p->data.id, p->data.title, p->data.credit);
        p = p->next;
    }
}

void deleteCourse() {
    int id;
    printf("Nhap ID khoa hoc can xoa: ");
    scanf("%d", &id);
    Node *p = head, *prev = NULL;
    while (p && p->data.id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        printf("==> Khong tim thay khoa hoc!\n");
        return;
    }
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("==> Da xoa khoa hoc!\n");
}

void updateCourse() {
    int id;
    printf("Nhap ID khoa hoc can cap nhat: ");
    scanf("%d", &id);
    Node *p = head;
    while (p && p->data.id != id)
        p = p->next;
    if (!p) {
        printf("==> Khong tim thay khoa hoc!\n");
        return;
    }
    getchar();
    printf("Nhap ten moi: "); fgets(p->data.title, 100, stdin);
    p->data.title[strcspn(p->data.title, "\n")] = '\0';
    printf("Nhap tin chi moi: "); scanf("%d", &p->data.credit);
    printf("==> Da cap nhat!\n");
}

void markCompleted() {
    int id;
    printf("Nhap ID khoa hoc da hoan thanh: ");
    scanf("%d", &id);
    Node *p = head, *prev = NULL;
    while (p && p->data.id != id) {
        prev = p;
        p = p->next;
    }
    if (!p) {
        printf("==> Khong tim thay khoa hoc!\n");
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

void sortCourses() {
    if (!head || !head->next) return;
    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.credit > j->data.credit) {
                Course temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("==> Da sap xep theo tin chi!\n");
}

void searchByTitle() {
    char keyword[100];
    getchar();
    printf("Nhap ten khoa hoc can tim: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    Node *p = head;
    int found = 0;
    while (p) {
        if (strstr(p->data.title, keyword)) {
            printf("ID: %d | Ten: %s | Tin chi: %d\n", p->data.id, p->data.title, p->data.credit);
            found = 1;
        }
        p = p->next;
    }
    if (!found)
        printf("==> Khong tim thay khoa hoc!\n");
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
        printf("\n=========== MENU ===========\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat khoa hoc\n");
        printf("5. Danh dau da hoan thanh\n");
        printf("6. Sap xep theo tin chi\n");
        printf("7. Tim theo ten\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addCourse(); break;
            case 2: displayCourses(); break;
            case 3: deleteCourse(); break;
            case 4: updateCourse(); break;
            case 5: markCompleted(); break;
            case 6: sortCourses(); break;
            case 7: searchByTitle(); break;
            case 8: freeAll(); printf("==> Thoat chuong trinh!\n"); break;
            default: printf("==> Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}