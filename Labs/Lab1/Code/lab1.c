#include <stdio.h>
#include <math.h>

int main ()
{
    float a, b, c;
 
    printf ("Input a:");
    scanf ("%f", &a);
    printf ("Input b:");
    scanf ("%f", &b);
 
    c = ((a - b)*(a - b)*(a - b)*(a - b)-(pow(a, 4) - 4*pow(a, 3)*b))/ (6*pow(a, 2)*pow(b, 2) - 4*a*pow(b, 3) + pow(b, 4));
 
    printf ("Result: %f\n", c);
 
    return 0;
}
