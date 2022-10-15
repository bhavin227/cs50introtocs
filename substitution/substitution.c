#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string s = argv[1];

    // checking when more than 2 string are given in input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // checking lenght of key is 26 or not
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // cheking whether key contain only alphabets
    else
    {
        int i = 0;
        while (i < strlen(argv[1]))
        {
            if (isalpha(s[i]) == 0)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else
            {
                i++;
            }
        }
    }

    // for checking duplicate char in string
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                return 1;
            }
        }
    }


    // taking plaintext form user
    string p = get_string("plaintext:  ");

    // printing ouput
    printf("ciphertext: ");

    // output funtion
    int i = 0;
    while (i < strlen(p))
    {
        if (isalpha(p[i]) && islower(p[i]))
        {
            int j = (int)p[i] - 97;
            printf("%c", tolower(s[j]));
            i++;
        }
        else if (isalpha(p[i]) && isupper(p[i]))
        {
            int j = (int)p[i] - 65;
            printf("%c", toupper(s[j]));
            i++;
        }
        else
        {
            printf("%c", p[i]);
            i++;
        }
    }
    printf("\n");
    return 0;
}