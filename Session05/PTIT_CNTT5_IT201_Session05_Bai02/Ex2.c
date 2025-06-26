#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tinhtong(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + tinhtong(n - 1);
    }
}
int main() {
    char chuoi[100];
    int n;

    printf("Nhap vao mot chuoi bat ky la : ");
    scanf("%s", chuoi);
    char *endptr;
    long val = strtol(chuoi, &endptr, 10);
    if (*endptr != '\0') {
        printf("Khong hop le\n");
    } else {
        n = (int)val;
        if (n < 0) {
            printf("Khong hop le\n");
        } else {
            int tong = tinhtong(n);
            printf("%d\n", tong);
        }
    }
    return 0;
}