#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char rotate(string p, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string s = argv[1];
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    // printf("%i\n", key);

    string p = get_string("plaintext:  ");
    // printf("length string p : %lu\n", strlen(p));

    printf("ciphertext: ");
    rotate(p, key);
    printf("\n");
}

char rotate(string p, int key)
{
    int i = 0;
    char ch;
    while (i < strlen(p))
    {
        // printf("%i\n", p[i]);
        if (isalpha(p[i]))
        {
            int ki = p[i] + key;
            if ((isupper(p[i]) != 0) && (ki > 90))
            {
                if (key >= 26)
                {
                    int k = round(key / 26) * 26;
                    k = key - k;
                    ch = p[i] + k;
                    printf("%c", ch);
                    i++;
                }
                else if (key < 26)
                {
                    int k = 26;
                    ch = p[i] + key - k;
                    printf("%c", ch);
                    i++;
                }
            }
            else if ((islower(p[i]) != 0) && (ki > 122))
            {
                if (key >= 26)
                {
                    int k = round(key / 26) * 26;
                    k = key - k;
                    ch = p[i] + k;
                    if ((int)ch > 122)
                    {
                        ch = ch - 122;
                        ch = 96 + ch;
                        printf("%c", ch);
                        i++;
                    }
                    else
                    {
                        printf("%c", ch);
                        i++;
                    }
                }
                else if (key < 26)
                {
                    int k = 26;
                    ch = p[i] + key - k;
                    printf("%c", ch);
                    i++;
                }
            }
            else
            {
                ch = p[i] + key;
                printf("%c", ch);
                i++;
            }
        }
        else
        {
            ch = p[i];
            printf("%c", ch);
            i++;
        }
    }
    return ch;
}