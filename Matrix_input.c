#include <stdio.h>
int insert();
int main()
{
    int n=3;
    int A[n][n];
    A=insert();
    return 0;
}
int** insert()
{
    int n=3,i,j;
    int A[n][n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            printf("\nInput value %i, %i: ", 1+i,1+j);
            scanf("%i",&A[i][j]);
            }
    return A;
}

