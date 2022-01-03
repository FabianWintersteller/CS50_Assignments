#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through columns
    for (int i = 0; i < height; i++)
    {
        //Iterate through rows
        for (int j = 0; j < width; j++)
        {
            //Assign colours to float variable
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //Calculate average
            int average = round((red + green + blue) / 3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through columns
    for (int i = 0; i < height; i++)
    {
        //Iterate through rows
        for (int j = 0; j < width; j++)
        {
            //Assign original colours to float variable
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            //Calculate sepia red
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);

            //Check the cap value
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            //Calculate sepia green
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);

            //Check the cap value
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            //Calculate sepia blue
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            //Check the cap value
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //Assign new colours
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through columns
    for (int i = 0; i < height; i++)
    {
        //Iterate through half the row (exchange)
        for (int j = 0; j < (width / 2); j++)
        {
            //Store left-sided pixels in temporary variable
            RGBTRIPLE temp = image[i][j];

            //Exchange equivalent right-sided pixel to the left side
            image[i][j] = image[i][width - (j + 1)];

            //Exchange left-sided pixel from temp to the right side
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //TEMPORARY STORAGE
    //Initialize temporary storage
    RGBTRIPLE temp[height][width];

    //Iterate through columns
    for (int i = 0; i < height; i++)
    {
        //Iterate through rows
        for (int j = 0; j < width; j++)
        {
            //store pixels in temporary array (to calculate)
            temp[i][j] = image[i][j];
        }
    }

    //CHECK FOR SURROUNDING PIXELS AND ASSIGN NEW VALUES
    //Iterate through columns
    for (int i = 0; i < height; i++)
    {
        //Iterate through rows
        for (int j = 0; j < width; j++)
        {
            //Initialize sum variables
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;

            //Iterate vertically
            for (int column = -1; column < 2; column++)
            {
                //Iterate horizontally
                for (int row = -1; row < 2; row++)
                {
                    //Check if pixels are outside vertically
                    if (i + column < 0 || i + column >= height)
                    {
                        continue;
                    }

                    //Check if pixals are outside horizontally
                    if (j + row < 0 || j + row >= width)
                    {
                        continue;
                    }

                    //Add up sums of surrounding pixels
                    sumRed += temp[i + column][j + row].rgbtRed;
                    sumGreen += temp[i + column][j + row].rgbtGreen;
                    sumBlue += temp[i + column][j + row].rgbtBlue;
                    counter++;
                }
            }
            //Calculate and assign new values
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
    return;
}
