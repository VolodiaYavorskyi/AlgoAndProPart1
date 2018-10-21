#include <stdio.h>
#include <cs50.h>

int main()
{
    int height, line, space, hash;
    
    do
    {
        printf("Height:");
        height = GetInt();                        
    } while (height < 0 || height > 23);
    
    for (line = 1; line <= height; line++)
    {
        for(space = height - line; space > 0; space--)
        {
            printf(" ");
        }
        for(hash = 0; hash <= line; hash++)
        {
            printf("#");
        }        
        printf("\n");
    }            
}
