#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage : ./vigenere key");
        return 1;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage : ./vigenere key (alphabetical)");
            return 1;
        }
    }
    
    printf("Please, enter the text you want to encipher :");
    string text = GetString();
    
    string key = argv[1];
    int keylen = strlen(key);
    
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {            
        int k = tolower(key[j % keylen]) - 'a';
        
        if (isupper(text[i]))
        {
            printf("%c", 'A' + (text[i] - 'A' + k) % 26);
            j++;
        }
        else if (islower(text[i]))
        {
            printf("%c", 'a' + (text[i] - 'a' + k) % 26);
            j++;
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");

    return 0;
}
