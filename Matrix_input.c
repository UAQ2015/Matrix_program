#include <stdio.h>
#include <math.h>
void multiplication(int size1, int size2, int size3, int **matrixres,int **matrix1,int **matrix2);
int determinant(int size, int **matrix);
void scalar_multiplication(int size1, int size2, int **matrix1, int **matrix_result,int scalar);
void inverse_matrix (int size, int **matrix, int **inverse_matrix);
void insert(int size1, int size2, int **matrix);
void add( int size1, int size2, int **matrix1,int **matrix2,int **matrix3);
void substract(int size1, int size2, int **matrix1,int **matrix2,int **matrix3);
void transpose (int size1, int size2, int **matrix, int **transposed_matrix);
void print_matrix (int size1, int size2, int **matrix);
void menu (void);
void insert_null(int size1, int size2 ,int **matrix);
int **calloc_matrix( int size1, int size2);
void free_matrix(int **matrix, int size1);
int main()
{
	menu();	
	return 0;
}

void menu ()
{
	int option=9, result;
	int size1, size2, size3; 
	int scalar;
	int **matrix1,**matrix2,**matrix3;
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
				printf("\nGive me the number of rows: ");
				scanf("%i",&size1);
				printf("\nGive me the number of columns: ");
				scanf("%i",&size2);
				matrix1=calloc_matrix(size1,size2);
				matrix2=calloc_matrix(size1,size2);
				matrix3=calloc_matrix(size1,size2);
				printf("\nGive me matrix 1\n");
				insert(size1,size2, matrix1);
				printf("Give me matrix 2\n");
				insert(size1,size2, matrix2);
				insert_null(size1,size2, matrix3);
				add(size1,size2, matrix1, matrix2, matrix3);
				print_matrix(size1,size2, matrix3);
				free_matrix(matrix1,size1);
				free_matrix(matrix2,size1);
				free_matrix(matrix3,size1);
				break;
			case 2:
				printf("\nGive me the number of rows: ");
				scanf("%i",&size1);
				printf("\nGive me the number of columns: ");
				scanf("%i",&size2);
				matrix1=calloc_matrix(size1,size2);
				matrix2=calloc_matrix(size1,size2);
				matrix3=calloc_matrix(size1,size2);
				printf("\nGive me matrix 1\n");
				insert(size1,size2, matrix1);
				printf("Give me matrix 2\n");
				insert(size1,size2, matrix2);
				insert_null(size1,size2, matrix3);
				substract(size1,size2, matrix1, matrix2, matrix3);
				print_matrix(size1,size2, matrix3);
				free_matrix(matrix1,size1);
				free_matrix(matrix2,size1);
				free_matrix(matrix3,size1);
				break;
			case 3:
				printf("\nGive me the number of rows: ");
				scanf("%i",&size1);
				printf("\nGive me the number of columns: ");
				scanf("%i",&size2);
				printf("\nGive me the number of rows of the second matrix: ");
				scanf("%i",&size3);
				matrix1=calloc_matrix(size1,size2);
				matrix2=calloc_matrix(size2,size3);
				matrix3=calloc_matrix(size1,size3);
				printf("\nGive me matrix 1\n");
				insert(size1,size2,matrix1);
				printf("Give me matrix 2\n");
				insert(size2,size3,matrix2);
				insert_null(size1,size3,matrix3);
				multiplication(size1,size2,size3,matrix3,matrix1,matrix2);
				print_matrix(size1,size3, matrix3);
				free_matrix(matrix1,size1);
				free_matrix(matrix2,size2);
				free_matrix(matrix3,size1);
				break;
			case 4:
				printf("\nGive me the number of rows: ");
				scanf("%i",&size1);
				printf("\nGive me the number of columns: ");
				scanf("%i",&size2);
				matrix1=calloc_matrix(size1,size2);
				matrix3=calloc_matrix(size1,size2);
				printf("\nGive me the matrix\n");
				insert(size1,size2,matrix1);
				printf("Give the scalar\n");
				scanf("%i", &scalar);
				insert_null(size1,size2,matrix3);
				scalar_multiplication(size1,size2,matrix1,matrix3,scalar);
				print_matrix(size1,size2, matrix3);
				free_matrix(matrix1,size1);
				free_matrix(matrix3,size1);
				break;
			case 5:
				printf("\nGive me the dimention of the matrix: ");
				scanf("%i",&size1);
				matrix1=calloc_matrix(size1,size1);
				printf("\nGive me the matrix\n");
				insert(size1,size1,matrix1);
				result=determinant(size1,matrix1);
				printf("\nYour determinant is: %i\n", result);
				free_matrix(matrix1,size1);
				break;
			case 6:
				printf("\nGive me the number of rows: ");
				scanf("%i",&size1);
				printf("\nGive me the number of columns: ");
				scanf("%i",&size2);
				matrix1=calloc_matrix(size1,size2);
				matrix2=calloc_matrix(size2,size1);
				printf("\nGive me matrix 1\n");
				insert(size1,size2,matrix1);
				insert_null(size2,size1,matrix2);
				transpose(size1,size2,matrix1,matrix2);
				print_matrix(size2,size1,matrix2);
				free_matrix(matrix1,size1);
				free_matrix(matrix2,size2);
				break; 
			case 7:
				printf("\nGive me the size: ");
				scanf("%i",&size1);
				printf("\nGive me the matrix: ");
				insert(size1,size1, matrix1);
				if (determinant(size1, matrix1) == 0)
					printf("\nThe matrix given has no inverse matrix. The determinant is zero.");
				else 
				{
					inverse_matrix(size1, matrix1, matrix2);				
					print_matrix(size1,size1, matrix2);
				}
				free_matrix(matrix1,size1);
				break;
			case 0:
				break;
		} 
	}while(option!=0);
}
int **calloc_matrix(int size1, int size2)
{
	int i=0;
	int **matrix;
	matrix=calloc(sizeof(int *),size1);
	for(i=0; i<size1; i++)
		matrix[i]=calloc(sizeof(int),size2);
	return matrix;
}
void free_matrix(int **matrix, int size1)
{
	int i=0;
	for(i=0; i<size1; i++)
		free(matrix[i]);
	free(matrix);
}
void scalar_multiplication(int size1, int size2, int **matrix1, int **matrix_result,int scalar)
{
	int row,col;
        for (row=0;row<size1;row++)
                for (col=0;col<size2;col++)       
			matrix_result[row][col]=scalar*matrix1[row][col];
}	

void insert(int size1, int size2, int **matrix)
{
	int row,col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			printf("\nInput value in row  %i and column  %i: ", 1+row,1+col);
			scanf("%i",&matrix[row][col]);
		}
}
void insert_null(int size1, int size2 ,int **matrix)
{
	int row,col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
			matrix[row][col]=0;
}

void multiplication(int size1, int size2, int size3, int **matrixres,int **matrix1,int **matrix2)
{
	int row,col,aux;
	for(row=0;row<size1;row++)
		for(col=0;col<size3;col++)
			for(aux=0,matrixres[row][col]=0;aux<size2;aux++)
				matrixres[row][col]=matrixres[row][col]+matrix1[row][aux]*matrix2[aux][col];
}
int determinant(int size, int **matrix)
{
	int i,j,h;
	int pow;
	int result =0;
	if (size==1)
		return matrix[0][0];
	else
	{
		int **submatrix;
		submatrix=calloc_matrix(size-1,size-1);
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
		free_matrix(submatrix,size-1);
		return result;
	}
}
void add( int size1, int size2, int **matrix1,int **matrix2,int **matrix3)
{
	int row, col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			matrix3[row][col]=matrix1[row][col]+matrix2[row][col];
		}
}

void substract(int size1, int size2, int **matrix1,int **matrix2,int **matrix3)
{
	int row, col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			matrix3[row][col]=matrix1[row][col]-matrix2[row][col];
		}
}


void transpose (int size1, int size2, int **matrix, int **transposed_matrix)
{
	int row, col;
	for (row = 0; row < size1; row++)
		for(col = 0; col < size2; col++)
			transposed_matrix[col][row] = matrix[row][col];
}

void print_matrix (int size1, int size2, int **matrix)
{
	int row,col;
	printf("\nYour result is:\n");
	for (row=0;row<size1;row++)
	{    
		for (col=0;col<size2;col++)   
			printf(" %i   ", matrix[row][col]);
		printf("\n");
	}    
}

void inverse_matrix (int size, int **matrix, int **inverse_matrix)
{
	int **cofactor_matrix;
	cofactor_matrix=calloc_matrix(size,size);
	int ** submatrix;
	submatrix=calloc_matrix(size-1,size-1);
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
	for (row = 0; row < size; row++)
		for (col = 0; col < size; col++)
			inverse_matrix[row][col] = det * cofactor_matrix[col][row];
	free_matrix(cofactor_matrix, size);
	free_matrix(submatrix, size-1);
	
			
}	
