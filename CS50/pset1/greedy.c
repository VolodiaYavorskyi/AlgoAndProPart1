#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int counter = 0, x;
    float change;
    
    printf("O hai!");
    
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    } while (change <= 0);
    
    x = round(change * 100);
    
    while (x >= 25)
    {
        x -= 25;
        counter++;
    }
    while (x >= 10)
    {
        x -= 10;
        counter++;
    }
    while (x >= 5)
    {
        x -= 5;
        counter++;
    }
    while (x >= 1)
    {
        x -= 1;
        counter++;
    }
    printf("%d\n", counter);
}
