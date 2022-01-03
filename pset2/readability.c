#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //Get user input
    string text = get_string("Text: ");
    unsigned int len = strlen(text);

    float letter_count = 0;
    float word_count = 1;
    float sentence_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letter_count++;
        }

        else if (text[i] == ' ')
        {
            word_count++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }

        else
        {
            continue;
        }
    }

    float ratio = 100 / word_count;
    float S = sentence_count * ratio;
    float L = letter_count * ratio;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 0)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}