#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
    int id;
    char name[50];
    int age;
};
int main() {
    struct Student students[5];
    int i;
    printf("Nhap thong tin cho 5 sinh vien:\n");
    for (i = 0; i < 5; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Ten: ");
        scanf("%s", students[i].name);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }
    printf("\nMang sinh vien da nhap:\n");
    printf("[\n");
    for (i = 0; i < 5; i++) {
        printf("  { id: %d, name: \"%s\", age: %d }", students[i].id, students[i].name, students[i].age);
        if (i < 4) {
            printf(",\n");
        } else {
            printf("\n");
        }
    }
    printf("];\n");
    int searchId;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &searchId);
    int found = 0;
    for (i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            printf("\nThong tin sinh vien co ID %d:\n", searchId);
            printf("{ id: %d, name: \"%s\", age: %d }\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nSinh vien khong ton tai\n");
    }

    return 0;
}