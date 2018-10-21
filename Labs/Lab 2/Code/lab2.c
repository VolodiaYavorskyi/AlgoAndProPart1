#include <stdio.h>
#include <math.h>

int main()
{
    double a, S = 0;
    int n = 1;     
    
    do
    {
        a = pow(-1, (n-1)) / pow(n, n);        
        S += a;
        n++;        
    } while (a > 0.0001);
    printf("Result is: %lf\n", S);
}
