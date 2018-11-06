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
        if (A[i] % 7)
        {
            B[k] = A[i];
            printf("%d; ", B[k]);
            k++;
        }
    }
    printf("(without 7)\n");
    
    int p = 0;
    printf("C = ");
    for (int i = 0; i < k; i++, p++)
    {
        C[p] = B[i];
        printf("%d; ", C[p]);
        
        if (B[i] % 2)
        {
            p++;
            C[p] = 0;
            printf("%d; ", C[p]);  
        }
    }
    printf("(0 after odd)\n");
    
    return 0;
}
