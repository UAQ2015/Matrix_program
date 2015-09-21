#include <stdio.h>
#include <math.h>
void multiplication(int size,int matrixres[size][size],int matrix1[size][size],int matrix2[size][size]);
int determinant(int size, int matrix[size][size]);
void insert(int size,int matrix[size][size]);
void insert_null(int size,int matrix[size][size]);
void add( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size]);
void substract( int size, int matrix1[size][size],int matrix2[size][size],int matrix3[size][size]);
void transpose (int size, int matrix[size][size], int transposed_matrix[size][size]);
void print_matrix (int size, int matrix [size][size]);
void inverse_matrix (int size, int matrix[size][size], int inverse_matrix[size][size]);
void menu (void);
int main()
{
    menu();	
    return 0;
}

void menu ()
{
	int option=0, result;
	int size=3;
    	int matrix1[size][size];
	int matrix2[size][size];
	int matrix3[size][size];
	do
	{
	do
	{
		printf("\nClick the number of what do you want to do\n");
		printf("1.- Add\n2.- Substract\n3.- Multiplication\n4.- Determinant\n5.- Transpose\n6.- Inverse\n7.- Exit ");
		scanf("%i", &option);
		if(option>7||option==0)
		{
			printf("Incorrect number, try again");
			option=0;
		}	
	}while(option==0);
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
                        multiplication(size,matrix3,matrix1,matrix2);
                        print_matrix(size, matrix3);
                        break;
		case 4:
			printf("Give me the matrix");
			insert(size,matrix1);
			result=determinant(size,matrix1);
			printf("\nYour determinant is: %i\n", result);
			break;
		case 5:
			printf("Give me matrix 1\n");
			insert(size,matrix1);
                        insert_null(size,matrix2);
			transpose(size,matrix1,matrix2);
			print_matrix(size,matrix2);
			break; 
		case 6:
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
				print_matrix(size, matrix2);
			}
			break;
		case 7:
			break;
	} 
	}while(option!=7);
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
void insert_null(int size,int matrix[size][size])
{
    int row,col;
    for (row=0;row<size;row++)
        for (col=0;col<size;col++)
            matrix[row][col]=0;
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
	int det;
	det = (1/ determinant(size, matrix));
	inverse_matrix [0][0] = det * ((matrix [1][1] * matrix [2][2]) - (matrix [1][2] * matrix [2][1]));
	inverse_matrix [0][1] = det * ((matrix [2][1] * matrix [0][2]) - (matrix [2][2] * matrix [0][1]));	
	inverse_matrix [0][2] = det * ((matrix [0][1] * matrix [1][2]) - (matrix [0][2] * matrix [1][1]));	
	inverse_matrix [1][0] = det * ((matrix [1][2] * matrix [2][0]) - (matrix [1][0] * matrix [2][2]));	
	inverse_matrix [1][1] = det * ((matrix [2][2] * matrix [0][0]) - (matrix [2][0] * matrix [0][2]));	
	inverse_matrix [1][2] = det * ((matrix [0][2] * matrix [1][0]) - (matrix [0][0] * matrix [1][2]));	
	inverse_matrix [2][0] = det * ((matrix [1][0] * matrix [2][1]) - (matrix [1][1] * matrix [2][0]));	
	inverse_matrix [2][1] = det * ((matrix [2][0] * matrix [0][1]) - (matrix [2][1] * matrix [0][0]));	
	inverse_matrix [2][2] = det * ((matrix [0][0] * matrix [1][1]) - (matrix [0][1] * matrix [1][0]));	
}	
