#include <stdio.h>
#include <math.h>

int main ()
{
    double a, b, c;
 
    printf ("Input a:");
    scanf ("%lf", &a);
    printf ("Input b:");
    scanf ("%lf", &b);
 
    c = ((a - b)*(a - b)*(a - b)*(a - b)-(pow(a, 4) - 4*pow(a, 3)*b))/ (6*pow(a, 2)*pow(b, 2) - 4*a*pow(b, 3) + pow(b, 4));
 
    printf ("Result: %lf\n", c);
 
    return 0;
}
