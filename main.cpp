#include "Matrix_input.h"
#include <iostream>

void menu (void);

int main()
{
	menu();
	return 0;
}

void menu ()
{
	int option=9, print_mode;
	int size1, size2, size3;
	float scalar,result;
	float **matrix1,**matrix2,**matrix3;
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
				printf("if you want to create a file with the answer press 1\n");
				scanf("%i", &print_mode);
				if(print_mode==1)
					print_file (size1, size2, matrix3);
				else
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
				printf("if you want to create a file with the answer press 1\n");
                                scanf("%i", &print_mode);
                                if(print_mode==1)
                                        print_file (size1, size2, matrix3);
                                else
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
				printf("if you want to create a file with the answer press 1\n");
                                scanf("%i", &print_mode);
                                if(print_mode==1)
                                        print_file (size1, size3, matrix3);
                                else
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
				scanf("%f", &scalar);
				insert_null(size1,size2,matrix3);
				scalar_multiplication(size1,size2,matrix1,matrix3,scalar);
				printf("if you want to create a file with the answer press 1\n");
                                scanf("%i", &print_mode);
                                if(print_mode==1)
                                        print_file (size1, size2, matrix3);
                                else
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
				printf("\nThe determinant is: %f\n",result);
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
				printf("if you want to create a file with the answer press 1\n");
                                scanf("%i", &print_mode);
                                if(print_mode==1)
                                        print_file (size1, size2, matrix3);
                                else
                                        print_matrix(size1,size2, matrix3);

				free_matrix(matrix1,size1);
				free_matrix(matrix2,size2);
				break;
			case 7:
				printf("\nGive me the size: ");
				scanf("%i",&size1);
				matrix1=calloc_matrix(size1,size1);
				matrix2=calloc_matrix(size1,size1);
				printf("\nGive me the matrix: ");
				insert(size1,size1, matrix1);
				if (determinant(size1, matrix1) == 0)
					printf("\nThe matrix given has no inverse matrix. The determinant is zero.");
				else
				{
					inverse_matrix(size1, matrix1, matrix2);
					printf("if you want to create a file with the answer press 1\n");
                               		 scanf("%i", &print_mode);
                                	if(print_mode==1)
                                        	print_file (size1, size1, matrix2);
                                	else
                                        	print_matrix(size1,size1, matrix2);

				}
				free_matrix(matrix1,size1);
				free_matrix(matrix2,size1);
				break;
			case 0:
				break;
		}
	}while(option!=0);
}
