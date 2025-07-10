#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
} Customer;

Customer queue[MAX_SIZE];
int front = 0;
int rear = 0;
int size = 0;

// Ham them khach hang vao hang doi
void enqueue(Customer customer) {
    if (size == MAX_SIZE) {
        printf("Hang doi da day. Khong the them khach hang moi.\n");
        return;
    }

    strcpy(queue[rear].name, customer.name);
    rear = (rear + 1) % MAX_SIZE;
    size++;

    printf("Da them khach hang %s vao hang doi.\n", customer.name);
}

// Ham phuc vu khach hang
void dequeue() {
    if (size == 0) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Dang phuc vu khach hang: %s\n", queue[front].name);
    front = (front + 1) % MAX_SIZE;
    size--;
}

// Ham hien thi danh sach khach hang dang cho
void displayQueue() {
    if (size == 0) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Danh sach khach hang dang cho:\n");
    int i;
    int index = front;
    for (i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, queue[index].name);
        index = (index + 1) % MAX_SIZE;
    }
}

int main() {
    int choice;
    Customer newCustomer;

    do {
        printf("\nMENU\n");
        printf("1. Them khach hang moi vao hang doi\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach hang dang cho\n");
        printf("4. Thoat chuong trinh\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang (toi da 30 ky tu): ");
                fgets(newCustomer.name, sizeof(newCustomer.name), stdin);
                newCustomer.name[strcspn(newCustomer.name, "\n")] = 0;
                enqueue(newCustomer);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 4);

    return 0;
}