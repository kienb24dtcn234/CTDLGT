#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main() {
    char str[100];
    printf("Nhap vao chuoi ky tu bat ky: ");
    scanf("%s", str);
    if (strlen(str) == 0) {
        printf("Chuoi khong hop le\n");
        return 0;
    }
    printf("Ket qua truoc khi sap xep: %s\n", str);
    sortString(str);
    printf("Ket qua sau khi sap xep: %s\n", str);
    return 0;
}