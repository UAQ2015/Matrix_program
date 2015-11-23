#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <string>

using namespace std;
/**
* Base class for Matrix
*/

class Matrix
{
public:
    Matrix(int _size1, int _size2);
    ~Matrix();
    void print_matrix ();
    void insert_null();
    void insert();
   /* void print_file ();*/
    int size1;
    int size2;
    float **matrix1;
    Matrix multiplication(Matrix matrix2);
    float determinant();
    Matrix scalar_multiplication(float scalar);
    Matrix inverse_matrix ();
    Matrix add(Matrix matrix2);
    Matrix substract(Matrix matrix2);
    Matrix transpose ();
};



#endif
