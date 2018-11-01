#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string name = GetString();
    
    if(name[0] >= 'a' && name[0] <= 'z')
    {
        printf("%c", name[0] - ('a' - 'A'));
    }
    else
    {
        printf("%c", name[0]);
    }
    
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' ' && name[i + 1] != ' ')
        {
            if(name[i + 1] >= 'a' && name[i + 1] <= 'z')
                {
                    printf("%c", name[i + 1] - ('a' - 'A'));
                }
                else
                {
                    printf("%c", name[i + 1]);
                }
        }
    }
    printf("\n");
}
