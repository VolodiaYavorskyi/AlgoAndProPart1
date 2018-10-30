#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n = 100;
    int A[n];
    int B[n];
    int C[n];
    
    printf("Enter the amount of elements in array A:");
    scanf("%d", &n);
    
    srand(time(0));
    
    printf("A = ");
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
        printf ("%d; ", A[i]);
    }
    printf("\n");
    
    int k = 0;
    printf("B = ");   
    for (int i = 0; i < n; i++)
    {
        if(A[i] % 7 == 0 && A[i] != 0)
            i++;       
        B[k] = A[i];
        if(i != n)
        {
            printf("%d; ", B[k]);
            k++;
        }
    }
    printf("(without 7)\n");
    
    int p = 0;
    printf("C = ");
    for (int i = 0; i < k; i++)
    {
        if(B[i] % 2 == 0)
        {
            C[p] = B[i];
            printf("%d; ", C[p]);
            p++;       
        }
        else
        {
            C[p] = B[i];
            printf("%d; ", C[p]);
            p++;
            C[p] = 0;
            printf("%d; ", C[p]);
            p++;
        }
    }
    printf("(0 after odd)\n");
    
    return 0;
}
