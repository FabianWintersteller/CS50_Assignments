#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n<1||n>8);

    for (int a=1; a<=n; a++)
    {
        //Space Front
        for(int i=n-a; i>0; i--)
        {
            printf(" ");
        }

        //Blocks Front
        for(int j=0; j<a; j++)
        {
            printf("#");
        }

        //Space Between
        if (n<9 && n>0)
        {
            printf("  ");
        }

        //Blocks Back
         for(int k=0; k<a; k++)
        {
            printf("#");
        }

    printf("\n");
    }
}


