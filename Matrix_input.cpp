#include "Matrix_input.h"
#include <iostream>

/*Piece::Piece(int _player, string position, PiecesArray &_board): board(_board) {
	player = _player;

	c = (int) (position[0] - 'a'); // letters are the columns
	r = (int) 8 - (position[1] - '0'); // numbers are rows
}*/

float **calloc_matrix(int size1, int size2)
{
	int i=0;
	float **matrix;
	matrix=calloc(sizeof(float *),size1);
	for(i=0; i<size1; i++)
		matrix[i]=calloc(sizeof(float),size2);
	return matrix;
}
void free_matrix(float **matrix, int size1)
{
	int i=0;
	for(i=0; i<size1; i++)
		free(matrix[i]);
	free(matrix);
}
Matrix Matrix::scalar_multiplication(float scalar)
{
    Matrix matrix2;
    matrix2->size1=size1;
    matrix2->size2=size2;
	int row,col;
        for (row=0;row<size1;row++)
                for (col=0;col<size2;col++)
                    matrix2->matrix1[row][col]=scalar*matrix1[row][col];
    return matrix2;
}

void Matrix::insert()
{
	int row,col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			std::cout<<"\nInput value in row: "<<1+row<<" and column: "<<1+col<<":";
			std::cin>>matrix1[row][col];
		}
}
void Matrix::insert_null()
{
	int row,col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
			matrix1[row][col]=0;
}

Matrix Matrix::multiplication(Matrix matrix2)
{
    Matrix matrix3;
    matrix3->size1=size1;
    matrix3->size2=matrix2->size2;
	int row,col,aux;
	for(row=0;row<size1;row++)
		for(col=0;col<matrix2->size2;col++)
			for(aux=0,matrix3->matrix1[row][col]=0;aux<size2;aux++)
				matrix3->matrix1[row][col]=matrix3->matrix1[row][col]+matrix1[row][aux]*matrix2->matrix1[aux][col];
    return matrix3;
}
float Matrix::determinant()
{
	int i,j,h;
	int pow;
	float result =0.0;
	if (size1==1)
		return matrix1[0][0];
	else
	{
        Matrix submatrix;
        submatrix->size1=size1-1;
        submatrix->size2=size2-1;
		//submatrix=calloc_matrix(size-1,size-1);
		for(i=0;i<size1;i++)
		{
			for(j=1;j<size1;j++)
				for(h=0;h<size1;h++)
				{
					if(h<i)submatrix->size1=size1;
						submatrix->matrix1[j-1][h]=matrix1[j][h];
					if(h>i)
						submatrix->matrix1[j-1][h-1]=matrix1[j][h];
				}
			pow=1;
			for(h=1;h<=i;h++)
				pow=pow*(-1);
			result=matrix1[0][i]*submatrix->determinant()*pow+result;
		}
		//free_matrix(submatrix,size-1);
		return result;
	}
}
Matrix Matrix::add(Matrix matrix2)
{
    Matrix matrix3;
    matrix3->size1=size1;
    matrix3->size2=size2;
	int row, col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			matrix3->matrix1[row][col]=matrix1[row][col]+matrix2->matrix1[row][col];
		}
    return matrix3;
}

Matrix Matrix::substract(Matrix matrix2)
{
    Matrix matrix3;
    matrix3->size1=size1;
    matrix3->size2=size2;
	int row, col;
	for (row=0;row<size1;row++)
		for (col=0;col<size2;col++)
		{
			matrix3->matrix1[row][col]=matrix1[row][col]-matrix2->matrix1[row][col];
		}
    return matrix3;
}


Matrix Matrix::transpose()
{
    Matrix matrix2;
    matrix2->size1=size1;
    matrix2->size2=size2;
	int row, col;
	for (row = 0; row < size1; row++)
		for(col = 0; col < size2; col++)
			matrix2->matrix1[col][row] = matrix1[row][col];
    return matrix2;
}

void Matrix::print_matrix()
{
	int row,col;
	std::cout<<"\nYour result is:\n";
	for (row=0;row<size1;row++)
	{
		for (col=0;col<size2;col++)
			std::cout<<matrix1[row][col]<<" ";
		std::cout<<"\n";
	}
}

void Matrix::print_file()
{
    int row,col;
	char name [100];
	FILE *pfile;
	printf("\nGive me the direcction and name of the file\n");
	scanf("%s", name);
	pfile=fopen(name,"w");
        fprintf(pfile, "Your result is:\n");
        for (row=0;row<size1;row++)
        {
                for (col=0;col<size2;col++)
                        fprintf(pfile," %f   ", matrix1[row][col]);
                fprintf(pfile,"\n");
        }
	fclose(pfile);
}

Matrix Matrix::inverse_matrix ()
{
	Matrix cofactor_matrix;
    cofactor_matrix->size1=size1;
    cofactor_matrix->size2=size2;
	Matrix submatrix;
    submatrix->size1=size1-1;
    submatrix->size2=size2-1;
    Matrix Inverse_matrix;
    Inverse_matrix->size1=size1;
    Inverse_matrix->size2=size2;
	//submatrix=calloc_matrix(size-1,size-1);
	//cofactor_matrix=calloc_matrix(size,size);
	int det, row, col, i, j;
	int pow , exp;
	det = (1/ Matrix->determinant();
	for (row = 0; row < size1; row++)
	{
		for (col = 0; col < size1; col++)
		{
			for (i = 0; i < size1; i++)
			{	for(j = 0; j < size1; j++)
				{
					if (i < row)
					{
						if (j < col)
							submatrix->matrix1[i][j] = matrix1[i][j];
						if (j > col)
							submatrix->matrix1[i][j - 1] = matrix1[i][j];
					}
					if (i > row)
					{
						if (j < col)
							submatrix->matrix1[i - 1][j] = matrix1[i][j];
						if (j > col)
							submatrix->matrix1[i - 1][j - 1] = matrix1[i][j];
					}
				}
			}
			exp = row + col;
			if ((exp%2)== 0)
			pow = 1;
			if ((exp%2)==1)
			pow = -1;
			cofactor_matrix->matrix1[col][row] = pow * (submatrix->determinant());
		}
	}
	for (row = 0; row < size1; row++)
		for (col = 0; col < size1; col++)
			Inverse_matrix->matrix1[row][col] = det * cofactor_matrix->matrix1[row][col];
	//free_matrix(cofactor_matrix, size);
	//free_matrix(submatrix, size-1);
}
