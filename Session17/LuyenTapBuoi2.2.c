#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100

typedef struct Node {
    char url[MAX_URL];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack backStack, forwardStack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s, char* url) {
    if (isStackEmpty(s)) {
        url[0] = '\0';
        return;
    }
    Node* temp = s->top;
    strcpy(url, temp->url);
    s->top = temp->next;
    free(temp);
}

void clearStack(Stack* s) {
    char temp[MAX_URL];
    while (!isStackEmpty(s)) {
        pop(s, temp);
    }
}

void visit() {
    char url[MAX_URL];
    getchar();
    printf("Nhap URL: ");
    fgets(url, MAX_URL, stdin);
    url[strcspn(url, "\n")] = '\0';
    push(&backStack, url);
    clearStack(&forwardStack);
    printf("==> Da truy cap: %s\n", url);
}

void back() {
    char url[MAX_URL];
    pop(&backStack, url);
    if (url[0] != '\0') {
        push(&forwardStack, url);
        printf("==> Quay lai: %s\n", url);
    } else {
        printf("==> Khong the quay lai!\n");
    }
}

void forward() {
    char url[MAX_URL];
    pop(&forwardStack, url);
    if (url[0] != '\0') {
        push(&backStack, url);
        printf("==> Tien toi: %s\n", url);
    } else {
        printf("==> Khong the tien toi!\n");
    }
}

void displayHistory() {
    if (isStackEmpty(&backStack)) {
        printf("==> Lich su rong!\n");
        return;
    }
    printf("\n--- Lich su truy cap ---\n");
    Stack temp;
    initStack(&temp);
    char url[MAX_URL];
    while (!isStackEmpty(&backStack)) {
        pop(&backStack, url);
        printf("%s\n", url);
        push(&temp, url);
    }
    while (!isStackEmpty(&temp)) {
        pop(&temp, url);
        push(&backStack, url);
    }
}

void freeStacks() {
    char temp[MAX_URL];
    while (!isStackEmpty(&backStack)) {
        pop(&backStack, temp);
    }
    while (!isStackEmpty(&forwardStack)) {
        pop(&forwardStack, temp);
    }
}

int main() {
    initStack(&backStack);
    initStack(&forwardStack);
    int choice;
    while (1) {
        printf("\n—————————— BROWSER HISTORY MANAGER ——————————\n");
        printf("1. VISIT: Truy cap mot website moi (nhap URL)\n");
        printf("2. BACK: Quay lai trang truoc do (hoan tac visit)\n");
        printf("3. FORWARD: Tien toi trang tiep theo (phuc hoi sau khi BACK)\n");
        printf("4. HISTORY: Hien thi danh sach lich su da truy cap\n");
        printf("5. THOAT: Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visit();
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                freeStacks();
                printf("==> Da thoat chuong trinh!\n");
                return 0;
            default:
                printf("==> Lua chon khong hop le!\n");
        }
    }
    return 0;
}