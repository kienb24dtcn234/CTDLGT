void addProduct() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Nhap ID: "); scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap ten san pham: "); fgets(newNode->data.name, 100, stdin);
    newNode->data.name[strcspn(newNode->data.name, "\n")] = '\0';
    printf("Nhap gia: "); scanf("%f", &newNode->data.price);
    newNode->next = head;
    head = newNode;
    printf("==> Da them san pham thanh cong!\n");
}

void displayProducts() {
    Node *p = head;
    if (!p) {
        printf("==> Danh sach rong!\n");
        return;
    }
    printf("\n--- Danh sach san pham dang co ---\n");
    while (p) {
        printf("ID: %d | Ten: %s | Gia: %.2f\n", p->data.id, p->data.name, p->data.price);
        p = p->next;
    }
}

void deleteProduct() {
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

void updateProduct() {
    int id;
    printf("Nhap ID san pham can cap nhat: ");
    scanf("%d", &id);
    Node *p = head;
    while (p && p->data.id != id)
        p = p->next;
    if (!p) {
        printf("==> Khong tim thay san pham!\n");
        return;
    }
    getchar();
    printf("Nhap ten moi: "); fgets(p->data.name, 100, stdin);
    p->data.name[strcspn(p->data.name, "\n")] = '\0';
    printf("Nhap gia moi: "); scanf("%f", &p->data.price);
    printf("==> Da cap nhat!\n");
}

void markSold() {
    int id;
    printf("Nhap ID san pham da ban: ");
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
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = p->data;
    newNode->prev = NULL;
    newNode->next = soldHead;
    if (soldHead) soldHead->prev = newNode;
    soldHead = newNode;
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("==> Da danh dau ban thanh cong!\n");
}

void displaySoldProducts() {
    DNode *p = soldHead;
    if (!p) {
        printf("==> Chua co san pham nao duoc ban!\n");
        return;
    }
    printf("\n--- Danh sach san pham da ban ---\n");
    while (p) {
        printf("ID: %d | Ten: %s | Gia: %.2f\n", p->data.id, p->data.name, p->data.price);
        p = p->next;
    }
}

void bubbleSortProducts() {
    if (!head || !head->next) return;
    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.price > j->data.price) {
                Product temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("==> Da sap xep theo gia tang dan!\n");
}

void searchByName() {
    char keyword[100];
    getchar();
    printf("Nhap ten san pham can tim: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    Node *p = head;
    int found = 0;
    while (p) {
        if (strstr(p->data.name, keyword)) {
            printf("ID: %d | Ten: %s | Gia: %.2f\n", p->data.id, p->data.name, p->data.price);
            found = 1;
        }
        p = p->next;
    }
    if (!found)
        printf("==> Khong tim thay san pham!\n");
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

case 4: updateProduct(); break;
case 5: markSold(); break;
case 6: displaySoldProducts(); break;
case 7: bubbleSortProducts(); break;
case 8: searchByName(); break;