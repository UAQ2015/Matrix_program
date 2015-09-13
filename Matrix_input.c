#include <stdio.h>
void multiplication(int size,int matrixres[size][size],int matrix1[size][size],int matrix2[size][size]);
void insert(int size,int matrix[size][size]);
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
void multiplication(int size,int matrixres[size][size],int matrix1[size][size],int matrix2[size][size])
{
    int row,col,aux;
    for(row=0;row<size;row++)
	for(col=0;col<size;col++)
		for(aux=0,matrixres[row][col]=0;aux<size;aux++)
			matrixres[row][col]=matrixres[row][col]+matrix1[row][aux]*matrix2[aux][col]
}

