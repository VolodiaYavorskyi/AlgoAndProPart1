#include <stdio.h>

void copyLines(int n, FILE *in, FILE *out);
int countVowels(FILE *fp);

int main()
{
    int k;
    
    printf("\nPrinting lines from k to k + 5\n");
    do
    {
        printf("Enter k: ");
        scanf("%d", &k);
    } while (k < 1 || k > 5);
    
    FILE *fp1;
    FILE *fp2;    
    
    fp1 = fopen("f1.txt", "r");
    
    if (fp1 == NULL)
    {
        printf("Error in opening file");
        return 1;
    }
    
    fp2 = fopen("f2.txt", "w");
    
    if (fp2 == NULL)
    {
        printf("Error in opening file");
        return 2;
    }
    
    copyLines(k, fp2, fp1);
    
    fclose(fp1);
    fclose(fp2);
    
    fp2 = fopen("f2.txt", "r");
    
    printf("There are %d vowels in f2.txt\n\n", countVowels(fp2));
    
    fclose(fp2);
    
    return 0;
}

void copyLines(int n, FILE *in, FILE *out)
{
    int i = 0;
    char buffer[50];
    
    while (!feof(out))
    {
        fgets(buffer, 50, out);
        i++;
        
        if (i >= n && i <= n + 5)
        {
            fputs(buffer, in);
        }
    }
}

int countVowels(FILE *fp)
{
    int counter = 0;
    char letter;
    
    while(!feof(fp))
    {
        letter = fgetc(fp);
        
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'|| letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
        {
            counter++;
        }
    }
    
    return counter;
}
