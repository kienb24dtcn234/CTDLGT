#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end)
{
    if (start > end)
    {
        return 1;
    }
    if (str[start] != str[end])
    {
        return 0;
    }
    return isPalindrome(str, start + 1, end -1);
}
int main()
{
    char str[100];
    printf("Nhap chuoi : ");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';
    }
    int result = isPalindrome(str, 0, strlen(str)-1);
    if (result) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}
