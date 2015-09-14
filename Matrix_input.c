#include <stdio.h>
#include <math.h>
void multiplication(int size,int matrixres[size][size],int matrix1[size][size],int matrix2[size][size]);
int determinant(int size, int matrix[size][size]);
void insert(int size,int matrix[size][size]);
int main()
{
    int size=3,det;
    int matrix[size][size];
    insert(size,matrix);
    printf("the determiant is: %i",determinat(size,matrix));
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
			matrixres[row][col]=matrixres[row][col]+matrix1[row][aux]*matrix2[aux][col];
}
int determinant(int size, int matrix[size][size])
{
    int result=0,i,j,h,pow;
    if (size==1)
	return matrix[0][0];
    else
    {
    	int submatrix[size-1][size-1];
	for(i=0;i<size;i++)
	{
		for(j=1;j<size;j++)
			for(h=0;h<size;h++)
				if(h<i)
				   submatrix[j-1][h]=matrix[j][h];
				if(h>i)
				   submatrix[j-1][h-1]=matrix[j][h];
		pow=1;
		for(h=1;h<=i;h++)
			pow=pow*(-1)
                result=matrix[0][i]*determinant(size-1,submatrix[0][i])*pow+result;	
	}
    return result;
    }
}

