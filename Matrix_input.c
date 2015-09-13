#include <stdio.h>
void insert(int size,int matrix[size][size]);
void add( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size]);
void substract( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size]);

int main()
{
    int size=3;
    int matrix[size][size];
    insert(size,matrix);
    return 0;
}
void insert(int size,int matrix[size][size])
{
    int row,col;
    for (row=0;row<size;row++)
        for (col=0;col<size;col++)
        {
            printf("\nInput value in row  %i and column  %i: ", 1+row,1+col);
            scanf("%i",&matrix[row][col]);
        }
}
void add( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size])
{
    int row, col;
    for (row=0;row<size;row++)
        for (col=0;col<size;col++)
        {
            matrix3[row][col]=matrix1[row][col]+matrix2[row][col];
        }
}

void substract( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size])
{
    int row, col;
    for (row=0;row<size;row++)
        for (col=0;col<size;col++)
        {
            matrix3[row][col]=matrix1[row][col]-matrix2[row][col];
        }
}


