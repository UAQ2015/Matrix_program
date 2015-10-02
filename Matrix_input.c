#include <stdio.h>
#include <math.h>
void multiplication(int size1, int size2, int size3, int matrixres[size1][size2], int matrix1[size2][size3], int matrix2[size1][size3]);
int determinant(int size, int matrix[size][size]);
void insert(int size, int matrix[size][size]);
void insert_null(int size, int matrix[size][size]);
void add( int size, int matrix1[size][size], int matrix2[size][size], int matrix3[size][size]);
void substract( int size, int matrix1[size][size], int matrix2[size][size], int matrix3[size][size]);
void transpose (int size, int matrix[size][size], int transposed_matrix[size][size]);
void print_matrix (int size, int matrix [size][size]);
void inverse_matrix (int size, int matrix[size][size], int inverse_matrix[size][size]);
void scalar_multiplication(int size, int matrix1[size][size], int matrix_result[size][size],int scalar);
void menu (void);
int main()
{
	menu();	
	return 0;
}

void menu ()
{
	int option=9, result;
	int size=3, scalar;
	int matrix1[size][size];
	int matrix2[size][size];
	int matrix3[size][size];
	do
	{
		do
		{
			printf("\nClick the number of what do you want to do\n");
			printf("1.- Add\n2.- Substract\n3.- Multiplication\n4.- Scalar multiplication\n5.- Determinant\n6.- Transpose\n7.- Inverse\n0.- Exit\n ");
			scanf("%i", &option);
			if(option>8)
			{
				printf("Incorrect number, try again");
				option = 9;
			}	
		}while(option == 9);
		switch(option)
		{
			case 1:
				printf("Give me matrix 1\n");
				insert(size, matrix1);
				printf("Give me matrix 2\n");
				insert(size, matrix2);
				insert_null(size, matrix3);
				add(size, matrix1, matrix2, matrix3);
				print_matrix(size, matrix3);
				break;
			case 2:
				printf("Give me matrix 1\n");
				insert(size, matrix1);
				printf("Give me matrix 2\n");
				insert(size, matrix2);
				insert_null(size, matrix3);
				substract(size, matrix1, matrix2, matrix3);
				print_matrix(size, matrix3);
				break;
			case 3:
				printf("Give me matrix 1\n");
				insert(size,matrix1);
				printf("Give me matrix 2\n");
				insert(size,matrix2);
				insert_null(size,matrix3);
				multiplication(size,size,size,matrix3,matrix1,matrix2);
				print_matrix(size, matrix3);
				break;
			case 4:
				printf("Give me the matrix\n");
				insert(size,matrix1);
				printf("Give the scalar\n");
				scanf("%i", &scalar);
				insert_null(size,matrix3);
				scalar_multiplication(size,matrix1,matrix3,scalar);
				print_matrix(size, matrix3);
				break;
			case 5:	

				printf("Give me the matrix\n");
				insert(size,matrix1);
				result=determinant(size,matrix1);
				printf("\nYour determinant is: %i\n", result);
				break;
			case 6:
				printf("Give me matrix 1\n");
				insert(size,matrix1);
				insert_null(size,matrix2);
				transpose(size,matrix1,matrix2);
				print_matrix(size,matrix2);
				break; 
			case 7:
				printf("\nATTENTION: This function only works with 3x3 matrices.");
				printf("\nGive me the matrix: ");
				insert(size, matrix1);
				if (size != 3)
				{
					printf("\nSorry! I wasn't programmed to work with matrices other than 3x3 matrices :(");
					break;
				}
				if (determinant(size, matrix1) == 0)
					printf("\nThe matrix given has no inverse matrix. The determinant is zero.");
				else 
				{
					inverse_matrix(size, matrix1, matrix2);				
				//	print_matrix(size, matrix2);
				}
				break;
			case 0:
				break;
		} 
	}while(option!=0);
}

void scalar_multiplication(int size, int matrix1[size][size], int matrix_result[size][size],int scalar)
{
	int row,col;
        for (row=0;row<size;row++)
                for (col=0;col<size;col++)       
			matrix_result[row][col]=scalar*matrix1[row][col];
}	

void insert(int size, int matrix[size][size])
{
	int row,col;
	for (row=0;row<size;row++)
		for (col=0;col<size;col++)
		{
			printf("\nInput value in row  %i and column  %i: ", 1+row,1+col);
			scanf("%i",&matrix[row][col]);
		}
}
void insert_null(int size, int matrix[size][size])
{
	int row,col;
	for (row=0;row<size;row++)
		for (col=0;col<size;col++)
			matrix[row][col]=0;
}

void multiplication(int size1, int size2, int size3, int matrixres[size1][size2], int matrix1[size2][size3], int matrix2[size1][size3])
{
	int row,col,aux;
	for(row=0;row<size1;row++)
		for(col=0;col<size3;col++)
			for(aux=0,matrixres[row][col]=0;aux<size2;aux++)
				matrixres[row][col]=matrixres[row][col]+matrix1[row][aux]*matrix2[aux][col];
}
int determinant(int size, int matrix[size][size])
{
	int i,j,h;
	int pow;
	int result =0;
	if (size==1)
		return matrix[0][0];
	else
	{
		int submatrix[size-1][size-1];
		for(i=0;i<size;i++)
		{
			for(j=1;j<size;j++)
				for(h=0;h<size;h++)
				{
					if(h<i)
						submatrix[j-1][h]=matrix[j][h];
					if(h>i)
						submatrix[j-1][h-1]=matrix[j][h];
				}
			pow=1;
			for(h=1;h<=i;h++)
				pow=pow*(-1);
			result=matrix[0][i]*determinant(size-1,submatrix)*pow+result;	
		}
		return result;
	}
}
void add( int size, int matrix1[size][size], int matrix2[size][size], int matrix3[size][size])
{
	int row, col;
	for (row=0;row<size;row++)
		for (col=0;col<size;col++)
		{
			matrix3[row][col]=matrix1[row][col]+matrix2[row][col];
		}
}

void substract( int size, int matrix1[size][size], int matrix2[size][size], int matrix3[size][size])
{
	int row, col;
	for (row=0;row<size;row++)
		for (col=0;col<size;col++)
		{
			matrix3[row][col]=matrix1[row][col]-matrix2[row][col];
		}
}


void transpose (int size, int matrix[size][size], int transposed_matrix[size][size])
{
	int row, col;
	for (row = 0; row < size; row++)
		for(col = 0; col < size; col++)
			transposed_matrix[col][row] = matrix[row][col];
}

void print_matrix (int size, int matrix [size][size])
{
	int row,col;
	printf("\nYour result is:\n");
	for (row=0;row<size;row++)
	{    
		for (col=0;col<size;col++)   
			printf(" %i   ", matrix[row][col]);
		printf("\n");
	}    
}

void inverse_matrix (int size, int matrix [size][size], int inverse_matrix [size][size])
{
	int cofactor_matrix[size][size];
	int submatrix[size-1][size-1];
	int det, row, col, i, j;
	int pow = -1;
	det = (1/ determinant(size, matrix));
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			for (i = 0; i < size; i++)
			{	for(j = 0; j < size; j++)
				{
					if (i < row)
					{
						if (j < col)
							submatrix[i][j] = matrix[i][j];
						if (j > col)
							submatrix[i][j - 1] = matrix[i][j];
					}
					if (i > row)
					{
						if (j < col)
							submatrix[i - 1][j] = matrix[i][j];
						if (j > col)
							submatrix[i - 1][j - 1] = matrix[i][j];
					}
				}
			}
			pow = pow * (-1);
			cofactor_matrix[col][row] = pow * (determinant(size - 1, submatrix));
		}
	}
//	for (row = 0; row < size; row++)
//		for (col = 0; col < size; col++)
//			inverse_matrix[row][col] = det * cofactor_matrix[col][row]
	print_matrix(size, cofactor_matrix);
}	
