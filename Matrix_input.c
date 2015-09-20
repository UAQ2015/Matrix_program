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
void menu (void);
int main()
{
    menu;	
    return 0;
}
void menu ()
{
	int option=0, result;
	int size=3;
    	int matrix1[size][size];
	int matrix2[size][size];
	int matrix3[size][size];

    	insert(size,matrix);
	do
	{
	do
	{
		printf("Click the number of what do you want to do\n");
		printf("1.- Add\n2.- Substract\n3.- Multiplication\n4.- Determinant\n5.- Transpose\n6.- Inverse\n7.- Exit ");
		scanf("%i", &option);
		if(option>7||option==0)
		{
			printf("Incorrect number, try again");
			option=0;
		}	
	}while(option==0);
	switch(option)
		case 1:
			insert(size,matrix1[size][size]);
			insert(size,matrix2[size][size]);
			insert_null(size,matrix3[size][size]);
			add(size,matrix1[size][size],matrix2[size][size],matrix3[size][size]);
			print_matrix(size, matrix3[size][size]);
			break;
		case 2:
			insert(size,matrix1[size][size]);
                        insert(size,matrix2[size][size]);
                        insert_null(size,matrix3[size][size]);
                        substract(size,matrix1[size][size],matrix2[size][size],matrix3[size][size]);
                        print_matrix(size, matrix3[size][size]);
                        break;
		case 3:
			insert(size,matrix1[size][size]);
                        insert(size,matrix2[size][size]);
                        insert_null(size,matrix3[size][size]);
                        multiplication(size,matrix3[size][size],matrix1[size][size],matrix2[size][size]);
                        print_matrix(size, matrix3[size][size]);
                        break;
		case 4:
			insert(size,matrix1[size][size]);
			result=determinant(size,matrix1);
			break;
		case 5:
						
			insert(size,matrix1[size][size]);
                        insert_null(size,matrix2[size][size]);
			transpose(matrix1[size][size],matrix2[size][size];
			print_matrix(size,matrix2[size][size]);
			break; 
		case 6:
			break;
		case 7:
			break;
	system("clear"); 
	}while(option!=7);
}
			
			
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
    for (row=0;row<size;row++)
    {    
	for (col=0;col<size;col++)   
            printf(" %i   ", matrix[row],matrix[col]);
        printf("\n");
    }    
}

	
