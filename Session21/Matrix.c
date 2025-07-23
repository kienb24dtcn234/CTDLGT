#include <stdio.h>

// tạo ma trận 2 chiều
int MATRIX[4][4];
// Hàm khởi tạo ma trận 2 chiều với các giá trị các ô là 0
int matrix()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            MATRIX[i][j]= 0;
        }
    }
}
// Khởi tạo hàm liên kết
void adjacency(int U, int V)
{
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;// Đồ thị vô hướng thì phải quan h 2 chiều
}
// Tạo hàm hiện thỉ ma trận
void printMATRIX()
{
for (int i = 0 ; i < 3 ; i++)
{
    for (int j = 0; j < 3; j ++)
    {
        printf("%d", MATRIX[i][j]);
    }
    printf("\n");
}
}
int main()
{

}