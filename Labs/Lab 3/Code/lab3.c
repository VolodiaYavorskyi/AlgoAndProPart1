#include <stdio.h>
#include <math.h>

int main()
{
    float e = 2.71828, X, Y, AN, AE, SN, SE;
    
    for (X = 1.0; X <= 2.0; X += 0.1)
    {
        Y = pow(e, X);
        AN = 1.0;
        AE = 1.0;
        SN = AN;
        SE = AE;
               
        for (int n = 0; n < 15; n++)
        {
            AN *= X / (n + 1);
            SN += AN;
        }
        
        for (int n = 0; AE > 0.0001; n++)
        {
            AE *= X / (n + 1);
            SE += AE;
        }
        
        printf("X=%.1f\tSN=%f\tSE=%f\tY=%f\n", X, SN, SE, Y);
    }
    return 0;
}
