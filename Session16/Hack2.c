#include <stdio.h>
#include <string.h>

#define MAX_SONGS 1000

// Cấu trúc bài hát
struct Song {
    char title[100];
};

// Queue để quản lý danh sách chờ phát
struct Queue {
    struct Song songs[MAX_SONGS];
    int front, rear;
    int size;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueFull(struct Queue *q) {
    return q->size == MAX_SONGS;
}

int isQueueEmpty(struct Queue *q) {
    return q->size == 0;
}

void enqueue(struct Queue *q, struct Song song) {
    if (isQueueFull(q)) {
        printf("Hàng đợi đã đầy!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SONGS;
    q->songs[q->rear] = song;
    q->size++;
}

struct Song dequeue(struct Queue *q) {
    struct Song empty = {" "};
    if (isQueueEmpty(q)) {
        printf("Hàng đợi trống!\n");
        return empty;
    }
    struct Song song = q->songs[q->front];
    q->front = (q->front + 1) % MAX_SONGS;
    q->size--;
    return song;
}

// Stack để lưu lịch sử phát
struct Stack {
    struct Song songs[MAX_SONGS];
    int top;
    int size;
};

void initStack(struct Stack *s) {
    s->top = -1;
    s->size = 0;
}

int isStackFull(struct Stack *s) {
    return s->size == MAX_SONGS;
}

int isStackEmpty(struct Stack *s) {
    return s->size == 0;
}

void push(struct Stack *s, struct Song song) {
    if (isStackFull(s)) {
        printf("Lịch sử đầy!\n");
        return;
    }
    s->top++;
    s->songs[s->top] = song;
    s->size++;
}

struct Song pop(struct Stack *s) {
    struct Song empty = {" "};
    if (isStackEmpty(s)) {
        printf("Lịch sử trống!\n");
        return empty;
    }
    struct Song song = s->songs[s->top];
    s->top--;
    s->size--;
    return song;
}

int main() {
    struct Queue nextQueue;
    struct Stack historyStack;
    initQueue(&nextQueue);
    initStack(&historyStack);

    char choice[10];
    while (1) {
        printf("——————————— MUSIC PLAYER ———————————\n");
        printf("ADD: Them bai hat x vao hang doi phat\n");
        printf("PLAY NEXT: Phat bai hat tiep theo trong hang doi\n");
        printf("PLAY PREVIOUS: Quay lai bai hat truoc\n");
        printf("HISTORY: Hien thi danh sach cac bai hat da phat\n");
        printf("EXIT: Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%s", choice);

        if (strcmp(choice, "EXIT") == 0) {
            printf("Da thoat chuong trinh!\n");
            break;
        } else if (strcmp(choice, "ADD") == 0) {
            struct Song song;
            printf("Nhap ten bai hat: ");
            scanf(" %[^\n]s", song.title);
            enqueue(&nextQueue, song);
            printf("Da them bai hat '%s' vao hang doi!\n", song.title);
        } else if (strcmp(choice, "PLAYNEXT") == 0) {
            if (!isQueueEmpty(&nextQueue)) {
                struct Song song = dequeue(&nextQueue);
                push(&historyStack, song);
                printf("Dang phat: %s\n", song.title);
            }
        } else if (strcmp(choice, "PLAY PREVIOUS") == 0) {
            if (!isStackEmpty(&historyStack)) {
                struct Song song = pop(&historyStack);
                enqueue(&nextQueue, song);
                printf("Quay lai: %s\n", song.title);
            }
        } else if (strcmp(choice, "HISTORY") == 0) {
            if (isStackEmpty(&historyStack)) {
                printf("Chua co bai hat nao trong lich su!\n");
            } else {
                printf("Lich su phat:\n");
                struct Stack temp;
                initStack(&temp);
                while (!isStackEmpty(&historyStack)) {
                    struct Song song = pop(&historyStack);
                    printf("%s\n", song.title);
                    push(&temp, song);
                }
                while (!isStackEmpty(&temp)) {
                    push(&historyStack, pop(&temp));
                }
            }
        } else {
            printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}