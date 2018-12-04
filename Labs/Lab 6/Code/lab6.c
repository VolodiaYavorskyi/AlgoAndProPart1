#include <stdio.h>
#include <string.h>

int main()
{
    char text[256];
    fgets(text, 256, stdin);
    
    int len = strlen(text);
    int firstWordLen = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
            break;
        firstWordLen++;
    }
    
    char word[firstWordLen + 1];
    
    for (int i = 0; i < firstWordLen; i++)
    {
        word[i] = text[i];
    }
    word[firstWordLen] = '\0';

    char A[10][10];
    int a = 0;
    int b = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            A[a][b] = '\0';
            a++;
            b = 0;
        }
        else 
        {
            A[a][b] = text[i];
            b++;
        }
    }
    A[a][b] = '\0';
    
    int counter = 0;
    for (int i = 1; i < 10; i++)
    {
        if (strcmp(A[i], word) == 0)
        {
            printf("%s ", word);
            counter++;
        }
    }
    
    printf("\nFirst word was used %d times\n", counter);
    
    return 0;
}
