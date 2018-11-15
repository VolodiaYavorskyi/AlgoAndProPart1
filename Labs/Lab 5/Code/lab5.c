#include <stdio.h>

int ortonorm(int n, int m, int A[n][m]);

int main()
{
    int n, m;
    n = m = 100;
    int A[n][m];
    
    printf("\nEnter the size of matrix\n");
    
    printf("Lines: ");
    do
    {
        scanf("%d", &n);
    } while (n < 2);
    
    printf("Columns: ");
    do
    {
        scanf("%d", &m);
    } while (m < 2);
    
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }   
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
    
    if(ortonorm(n, m, A))
        printf("\nMatrix is not ortonormal\n\n");
    else
        printf("\nMatrix is ortonormal\n\n");
}

int ortonorm(int n, int m, int A[n][m])
{
    int sum;
    
    // first line
    
    for (int i = 0; i < n; i++)
    {
        //second line
    
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum += A[i][k] * A[j][k];
            }
            if (i == j && sum!= 1)
                return 1;
            else 
                return 0;
            if (sum)
                return 1;
            else 
                return 0;
        }
    }
    return 1;
}
