#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_count(long x);
int sum_start(long x);
int sum_secondstart(long x);
void check_americanexpresscard(int count, long x);
void check_visacard(int count, long x);
void check_mastercard(int count, long x);

int main(void)
{
    long x = get_long("enter your credit card number : ");

    // for checking whether card is valid or not

    // Add the sum to the sum of the digits that weren’t multiplied by 2
    int sumstart = sum_start(x);

    // Multiply every other digit by 2, starting with 2nd last, and add digit
    int sumsecondstart = sum_secondstart(x);

    // checking ultimate validity
    int check = (sumstart + sumsecondstart) % 10;

    // for counting digit
    int count = get_count(x);

    // final checking
    if (check == 0 && (count == 13 || count == 15 || count == 16))
    {
        // for checking american express card
        check_americanexpresscard(count, x);

        // for checking visa card
        check_visacard(count, x);

        // for checking master card
        check_mastercard(count, x);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_count(long x)
{
    int count = 0;
    do
    {
        x /= 10;
        count = count + 1;
    }
    while (x != 0);
    return count;
}

int sum_start(long x)
{
    int sumstart = 0;
    long t = x;
    while (t != 0)
    {
        int r = t % 10;
        sumstart = sumstart + r;
        t = t / 100;
    }
    return sumstart;
}

int sum_secondstart(long x)
{
    int sumsecondstart = 0;
    long ti = round(x / 10);
    while (ti != 0)
    {
        long ri = (ti % 10) * 2;
        while (ri != 0)
        {
            int rii = ri % 10;
            sumsecondstart = sumsecondstart + rii;
            ri = round(ri / 10);
        }
        ti = ti / 100;
    }
    return sumsecondstart;
}

void check_americanexpresscard(int count, long x)
{
    if (count == 15)
    {
        int ae_check = round(x / 10000000000000);
        if (ae_check == 34 || ae_check == 37)
        {
            printf("AMEX\n");
        }
        else if (ae_check != 34 && ae_check != 37)
        {
            printf("INVALID\n");
        }
    }
}

void check_visacard(int count, long x)
{
    if (count == 13)
    {
        int visa_check = round(x / 1000000000000);
        if (visa_check == 4)
        {
            printf("VISA\n");
        }
    }
    else if (count == 16)
    {
        int visa_check = round(x / 1000000000000000);
        if (visa_check == 4)
        {
            printf("VISA\n");
        }
        else if (visa_check != 4 && count != 16)
        {
            printf("INVALID\n");
        }
    }
}

void check_mastercard(int count, long x)
{
    if (count == 16)
    {
        int master_check = round(x / 100000000000000);
        if (master_check < 56 && master_check > 50)
        {
            printf("MASTERCARD\n");
        }
        else if (master_check > 55 || master_check < 40)
        {
            printf("INVALID\n");
        }
    }
}