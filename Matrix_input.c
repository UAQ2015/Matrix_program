#include <stdio.h>
void insert(int A[n][n]);
int main()
{
    int n=3;
    int A[n][n];
    insert(A);
    return 0;
}
void insert(int A[n][n])
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            printf("\nInput value %i, %i: ", 1+i,1+j);
            scanf("%i",&A[i][j]);
            }
}

