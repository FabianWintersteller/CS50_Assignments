#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Enter Credit Card Number and Preparation
    long c = get_long("Number: ");
    long a = c;
    int n;
    int m = 0;
    
    //Credit Card Verification Alogrithm
    for (int i = 0; i < 10; i++)
    {
        int x = a % 10;

        int y = ((a / 10) % 10) * 2;

        if (y < 10)
        {
            n = x + y;
        }

        else
        {
            int z = y % 10 + y / 10 % 10;
            n = x + z;
        }

        m = m + n;

        a = a / 100;
    }
    
    //Checking type of Credit Card
    if (m % 10 != 0)
    {
        printf("INVALID\n");
    }

    else if (c >= 5000000000000000 && c < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }

    else if (c >= 340000000000000 && c < 350000000000000)
    {
        printf("AMEX\n");
    }
    
    else if ( c >= 370000000000000 && c < 380000000000000)
    {
        printf("AMEX\n");
    }

    else if ( c >= 4000000000000 && c < 5000000000000)
    {
        printf("VISA\n");
    }

    else if (c >= 4000000000000000 && c < 5000000000000000)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
