#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Prompt user for key and check key
int main(int argc, string argv[])
{
    //Check argument count
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Check if string only consists of letters
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        argv[1][i] = toupper(argv[1][i]);
        if (argv[1][i] < 65 || argv[1][i] > 90)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    //Check string length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Check individuality of string elements
    for (int m = 0; argv[1][m] != '\0'; m++)
    {
        for (int k = m + 1; argv[1][k] != '\0'; k++)
        {
            if (argv[1][m] == argv[1][k])
            {
                printf("Key must contain 26 individual characters.\n");
                return 1;
            }
        }
    }


    //Prompt user for plain text
    string plain = get_string("plaintext: ");

    //Convert plain text into cipher text
    printf("ciphertext: ");
    char c;
    for (int j = 0; plain[j] != '\0'; j++)
    {
        if (plain[j] >= 65 && plain[j] <= 90)
        {
            int p = plain[j] - 65;
            c = argv[1][p];
            printf("%c", c);
        }

        else if (plain[j] >= 97 && plain[j] <= 122)
        {
            int p = plain[j] - 97;
            c = argv[1][p];
            printf("%c", tolower(c));
        }

        else
        {
            printf("%c", plain[j]);
        }
    }

    printf("\n");
}