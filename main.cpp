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
	int _size1, _size2, _size3;
	float scalar,result;
	Matrix matrix1;
	Matrix matrix2;
	Matrix matrix3;

	matrix1.Resize(2,2);
	matrix1.insert();
	matrix1.print_matrix();
	Matrix b(2,2);
	cout<< "Pointer to matrix "<<b.matrix1<< endl;
	b.copy(matrix1.add(Matrix::Identity(2)));
	cout<< "Pointer to matrix "<<b.matrix1<< endl;
	b.print_matrix();

/*	do
	{
		do
		{
			cout<<"\nClick the number of what do you want to do\n";
			cout<<"1.- Add\n2.- Substract\n3.- Multiplication\n4.- Scalar multiplication\n5.- Determinant\n6.- Transpose\n7.- Inverse\n0.- Exit\n ";
			cin>>option;
			if(option>8)
			{
				cout<<"Incorrect number, try again";
				option = 9;
			}
		}while(option == 9);
		switch(option)
		{
			case 1:
				cout<<"\nGive me the number of rows: ";
				cin>>_size1;
				cout<<"\nGive me the number of columns: ";
				cin>>_size2;
//				matrix1=new Matrix(_size1,_size2);
//				matrix2=new Matrix(_size1,_size2);
//				matrix3=new Matrix(_size1,_size2);
				matrix1.Resize(_size1, _size2);
				matrix2.Resize(_size1, _size2);
				matrix3.Resize(_size1, _size2);
				cout<<"\nGive me matrix 1\n";
				matrix1.insert();
				cout<<"Give me matrix 2\n";
				matrix2.insert();
				matrix3.insert_null();
				matrix3=matrix1.add(matrix2);
				cout<<"if you want to create a file with the answer press 1\n";
				cin>>print_mode;
				if(print_mode==1)
					cout<<"not yet :p";//print_file (size1, size2, matrix3);
				else
					matrix3.print_matrix();
				break;
			case 2:
				cout<<"\nGive me the number of rows: ";
				cin>>_size1;
				cout<<"\nGive me the number of columns: ";
				cin>>_size2;
//				matrix1=new Matrix(_size1,_size2);
//				matrix2=new Matrix(_size1,_size2);
//				matrix3=new Matrix(_size1,_size2);
				matrix1.Resize(_size1, _size2);
				matrix2.Resize(_size1, _size2);
				matrix3.Resize(_size1, _size2);
				cout<<"\nGive me matrix 1\n";
				matrix1.insert();
				cout<<"Give me matrix 2\n";
				matrix2.insert();
				matrix3.insert_null();
				matrix3=matrix1.substract(matrix2);
				cout<<"if you want to create a file with the answer press 1\n";
                cin>>print_mode;
                if(print_mode==1)
                        cout<<"not yet :p";//print_file (size1, size2, matrix3);
                else
                        matrix3.print_matrix();
				break;
			case 3:
				cout<<"\nGive me the number of rows: ";
				cin>>_size1;
				cout<<"\nGive me the number of columns: ";
				cin>>_size2;
				cout<<"\nGive me the number of rows of the second matrix: ";
				cin>>_size3;
//				matrix1=new Matrix(_size1,_size2);
//				matrix2=new Matrix(_size2,_size3);
//				matrix3=new Matrix(_size1,_size3);
				matrix1.Resize(_size1, _size2);
				matrix2.Resize(_size2, _size3);
				matrix3.Resize(_size1, _size3);

				cout<<"\nGive me matrix 1\n";
				matrix1.insert();
				cout<<"Give me matrix 2\n";
				matrix2.insert();
				matrix3.insert_null();
				matrix3=matrix1.multiplication(matrix2);
				cout<<"if you want to create a file with the answer press 1\n";
                                cin>>print_mode;
                                if(print_mode==1)
                                        cout<<"not yet :p";//print_file (size1, size3, matrix3);
                                else
                                        matrix3.print_matrix();
				break;
			case 4:
				cout<<"\nGive me the number of rows: ";
				cin>>_size1;
				cout<<"\nGive me the number of columns: ";
				cin>>_size2;
//				matrix1=new Matrix(_size1,_size2);
//				matrix3=new Matrix(_size1,_size2);
				matrix1.Resize(_size1, _size2);
				matrix3.Resize(_size1, _size2);

				cout<<"\nGive me the matrix\n";
				matrix1.insert();
				cout<<"Give the scalar\n";
				cin>>scalar;
				matrix3.insert_null();
				matrix3=matrix1.scalar_multiplication(scalar);
				cout<<"if you want to create a file with the answer press 1\n";
                                cin>>print_mode;
                                if(print_mode==1)
                                        cout<<"not yet :p";//print_file (size1, size2, matrix3);
                                else
                                        matrix3.print_matrix();
				break;
			case 5:
				cout<<"\nGive me the dimention of the matrix: ";
				cin>>_size1;
//				matrix1=new Matrix(_size1,_size1);
				matrix1.Resize(_size1, _size1);

				cout<<"\nGive me the matrix\n";
				matrix1.insert();
				result=matrix1.determinant();
				cout<<"\nThe determinant is: "<<result<<"\n";
				break;
			case 6:
				cout<<"\nGive me the number of rows: ";
				cin>>_size1;
				cout<<"\nGive me the number of columns: ";
				cin>>_size2;
//				matrix1=new Matrix(_size1,_size2);
//				matrix2=new Matrix_size2,_size1);
				matrix1.Resize(_size1, _size2);
				matrix2.Resize(_size2, _size1);

				cout<<"\nGive me matrix 1\n";
				matrix1.insert();
				matrix2.insert_null();
				matrix2=matrix1.transpose();
				cout<<"if you want to create a file with the answer press 1\n";
                                cin>>print_mode;
                                if(print_mode==1)
                                        cout<<"not yet :p";//print_file (size1, size2, matrix3);
                                else
                                        matrix2.print_matrix();

				break;
			case 7: // Inverse
				cout<<"\nGive me the size: ";
				cin>>_size1;
//                matrix1=new Matrix(_size1,_size1);
//				matrix2=new Matrix(_size1,_size1);
				matrix1.Resize(_size1, _size1);
				matrix2.Resize(_size1, _size1);

				cout<<"\nGive me the matrix: ";
				matrix1.insert();
				if (matrix1.determinant() == 0)
					cout<<"\nThe matrix given has no inverse matrix. The determinant is zero.";
				else
				{
					matrix2=matrix1.inverse_matrix();
					cout<<"if you want to create a file with the answer press 1\n";
                    cin>>print_mode;
                    if(print_mode==1)
                            cout<<"not yet :p";//print_file (size1, size1, matrix2);
                    else
                            matrix2.print_matrix();

				}
				break;
			case 0:
				break;
		}
	}while(option!=0);
/* */
}
