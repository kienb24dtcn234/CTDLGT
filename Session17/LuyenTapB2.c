#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

typedef struct {
    char title[100]; // Tên bài hát
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int front, rear;
    int size;
} Queue;

typedef struct {
    Song songs[MAX_SONGS];
    int top;
    int size;
} Stack;

Queue nextQueue;
Stack historyStack;

void initQueue() {
    nextQueue.front = 0;
    nextQueue.rear = -1;
    nextQueue.size = 0;
}

void initStack() {
    historyStack.top = -1;
    historyStack.size = 0;
}

int isQueueFull() {
    return nextQueue.size == MAX_SONGS;
}

int isQueueEmpty() {
    return nextQueue.size == 0;
}

void enqueue(Song song) {
    if (isQueueFull()) {
        printf("==> Hàng đợi đã đầy!\n");
        return;
    }
    nextQueue.rear = (nextQueue.rear + 1) % MAX_SONGS;
    nextQueue.songs[nextQueue.rear] = song;
    nextQueue.size++;
    printf("==> Đã thêm bài hát '%s' vào hàng đợi!\n", song.title);
}

Song dequeue() {
    Song empty = {" "};
    if (isQueueEmpty()) {
        printf("==> Hàng đợi trống, không thể phát!\n");
        return empty;
    }
    Song song = nextQueue.songs[nextQueue.front];
    nextQueue.front = (nextQueue.front + 1) % MAX_SONGS;
    nextQueue.size--;
    return song;
}

int isStackEmpty() {
    return historyStack.size == 0;
}

void push(Song song) {
    if (historyStack.size == MAX_SONGS) {
        printf("==> Lịch sử đã đầy!\n");
        return;
    }
    historyStack.top++;
    historyStack.songs[historyStack.top] = song;
    historyStack.size++;
}

Song pop() {
    Song empty = {" "};
    if (isStackEmpty()) {
        printf("==> Không có lịch sử để quay lại!\n");
        return empty;
    }
    Song song = historyStack.songs[historyStack.top];
    historyStack.top--;
    historyStack.size--;
    return song;
}

void playNext() {
    if (isQueueEmpty()) {
        printf("==> Không còn bài hát để phát!\n");
        return;
    }
    Song song = dequeue();
    push(song);
    printf("==> Đang phát: %s\n", song.title);
}

void playPrevious() {
    if (isStackEmpty()) {
        printf("==> Không có bài hát trước đó!\n");
        return;
    }
    Song song = pop();
    enqueue(song);
    printf("==> Quay lại: %s\n", song.title);
}

void displayHistory() {
    if (isStackEmpty()) {
        printf("==> Chưa có bài hát nào trong lịch sử!\n");
        return;
    }
    printf("\n--- Lich su cac bai hat da phat ---\n");
    Stack temp;
    temp.top = -1;
    temp.size = 0;
    while (!isStackEmpty()) {
        Song song = pop();
        printf("%s\n", song.title);
        temp.top++;
        temp.songs[temp.top] = song;
        temp.size++;
    }
    while (temp.size > 0) {
        push(pop(&temp));
    }
}

int main() {
    initQueue();
    initStack();
    char choice[10];
    while (1) {
        printf("\n——————————— MUSIC PLAYER ———————————\n");
        printf("ADD: Them bai hat vao hang doi phat (queue)\n");
        printf("PLAY NEXT: Phat bai tiep theo tu queue -> luu vao stack\n");
        printf("PLAY PREVIOUS: Quay lai bai truoc (hien ten bai truoc trong stack)\n");
        printf("HISTORY: Hien thi lich su cac bai hat da phat\n");
        printf("EXIT: Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%s", choice);

        if (strcmp(choice, "EXIT") == 0) {
            printf("==> Da thoat chuong trinh!\n");
            break;
        } else if (strcmp(choice, "ADD") == 0) {
            Song song;
            getchar();
            printf("Nhap ten bai hat: ");
            fgets(song.title, 100, stdin);
            song.title[strcspn(song.title, "\n")] = '\0';
            enqueue(song);
        } else if (strcmp(choice, "PLAY NEXT") == 0) {
            playNext();
        } else if (strcmp(choice, "PLAY PREVIOUS") == 0) {
            playPrevious();
        } else if (strcmp(choice, "HISTORY") == 0) {
            displayHistory();
        } else {
            printf("==> Lua chon khong hop le!\n");
        }
    }
    return 0;
}