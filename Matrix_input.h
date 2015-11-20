#ifndef MATRIX_H
#define MATRIX_H

#include <string>

using namespace std;
/**
* Base class for Matrix
*/

class Matrix
{
private:
    int size1;
    int size2;
    float **matrix1;
    Matrix multiplication(Matrix matrix2);
    float determinant();
    Matrix scalar_multiplication(float scalar);
    Matrix inverse_matrix ();
    void insert();
    Matrix add(Matrix matrix2);
    Matrix substract(Matrix matrix2);
    Matrix transpose ();
    void print_matrix ();
    void insert_null();
    float **calloc_matrix(int size1, int size2);
    void free_matrix(float **matrix, int size1);
    void print_file ();
};



#endif
