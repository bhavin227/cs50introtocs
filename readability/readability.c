#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text : ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (letters / (float)words) * 100;
    //printf("%f\n", L);

    float S = (sentences / (float)words) * 100;
    //printf("%f\n", S);

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //printf("%i\n", index);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int l = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        while (isalpha(text[i]))
        {
            l++;
            i++;
        }
        i++;
    }

    //printf("%i\n", l);
    return l;
}

int count_words(string text)
{
    int l = 1;
    int i = 0;
    while (text[i] != '\0')
    {
        while (isalpha(text[i]))
        {
            i++;
        }
        if ((isspace(text[i])) == 0)
        {
            i = i + 1;
        }
        else
        {
            l++;
            i = i + 1;
        }

    }

    //printf("%i\n", l);
    return l;
}

int count_sentences(string text)
{
    int l = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        while (text[i] != 63 && text[i] != 46 && text[i] != 33)
        {
            i++;
        }
        i++;
        if (text[i] == 34)
        {
            i = i + 1;
        }
        else
        {
            l++;
        }
    }

    //printf("%i\n", l);
    return l;
}