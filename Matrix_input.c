#include <stdio.h>

int main()
{
    int n=3,i,j;
    int A[n][n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            printf("/nInput value %i, %j", i, j);
            scanf("%i", A[i][j]);
            }
    return 0;
}
