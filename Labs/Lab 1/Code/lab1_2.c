#include <stdio.h>

int main()
{
    int a, b, c, m, n;
    
    printf("input n:");
    scanf("%d", &n);
    printf("input m:");
    scanf("%d", &m);
    
    a = n++ * m;
    
    printf("%d++ * %d = %d \n", n, m, a);
    
    printf("input n:");    
    scanf("%d", &n);
    printf("input m:");
    scanf("%d", &m);
    
    b = n++ <m;
    
    printf("%d++ < %d = %d \n", n, m, b);
    
    printf("input n:");
    scanf("%d", &n);
    printf("input m:");
    scanf("%d", &m);
    
    c = n-- >m;
    
    printf("%d-- > %d = %d \n", n, m, c);
    
    return 0;
}
