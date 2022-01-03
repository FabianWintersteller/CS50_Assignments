#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Start size of population
    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);
    
    //End size of population
    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);
    
    //Calculate years
    int n;
    for (n = 0; x < y; n++)
    {
        x = x + x / 3 - x / 4;
    }
    printf("Years: %i\n", n);
}