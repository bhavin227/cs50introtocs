#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;

    // for input
    do
    {
        x = get_int("height ");
    }
    while (x < 1 || x > 8);

    // for main loop
    int y = 1;
    do
    {
        // for printing spaces
        for (int a = x; a > y; a--)
        {
            printf(" ");
        }

        // for print bricks #
        for (int z = 0; z < y; z++)
        {
            printf("#");
        }

        printf("  ");

        // for print bricks again#
        for (int z = 0; z < y; z++)
        {
            printf("#");
        }
        y = y + 1;
        printf("\n");
    }
    while (y > 1 && y <= x);
}