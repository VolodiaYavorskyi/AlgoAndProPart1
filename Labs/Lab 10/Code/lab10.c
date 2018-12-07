#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n");    
    
    int n;
    
    do 
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
    } while (n < 2);
    
    int *arr;
    arr = (int*)(malloc(n * sizeof(int)));
    
    srand(time(0));
    
    printf("\nOur array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d; ", arr[i]);
    }
    
    printf("\n\nAdding k elements after element l\n");
    
    int k, l;
    
    do 
    {
        printf("Enter k: ");
        scanf("%d", &k);
    } while (k < 1);
    
    do 
    {
        printf("Enter l: ");
        scanf("%d", &l);
    } while (l > n || l < 1);
    
    n += k;
    
    int *add;
    add = (int*)(malloc(n * sizeof(int)));    
    
    printf("Our new array: ");
    for (int i = 0; i < n; i++)
    {
        if (i >= l && i < l + k)
        {
            add[i] = rand() % 100;
        }
        else if (i < l)
        {
            add[i] = arr[i];
        }
        else if (i >= l + k)
        {
            add[i] = arr[i - k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", add[i]);
    }
    
    printf("\n\nDeleting k elements after element l\n");
    
    do 
    {
        printf("Enter k: ");
        scanf("%d", &k);
    } while (k < 1);
    
    do 
    {
        printf("Enter l: ");
        scanf("%d", &l);
    } while (l > n || l < 1);
    
    n -= k;
    
    int *delete = (int*)(malloc(n * sizeof(int)));
    
    printf("Our new array: ");
    for (int i = 0; i < n; i++)
    {
        if (i >= l && i < l + k)
        {
            delete[i] = add[i + k];
        }
        else if (i < l)
        {
            delete[i] = add[i];
        }    
        else if (i >= l + k)
        {
            delete[i] = add[i + k];
        } 
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", delete[i]);
    }
    
    free(arr);
    free(add);
    free(delete);
    
    printf("\n\n");
    
    return 0;
}
