#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage : ./caesar key");
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    printf("Please, enter the text you want to encipher :\n");
    string text = GetString();
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] + key - 65) % 26;
            printf("%c", text[i] + 65);
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] + key - 97) % 26;
            printf("%c", text[i] + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    
    return 0;      
}
