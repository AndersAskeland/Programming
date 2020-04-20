#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgRGB = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/3;
            image[i][j].rgbtBlue = avgRGB;
            image[i][j].rgbtRed = avgRGB;
            image[i][j].rgbtGreen = avgRGB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tempImg;
            tempImg = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tempImg;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Define copy variable
    RGBTRIPLE copyImage[height][width];

    // Variables i need
    int sumRed = 0;
    int sumBlue = 0;
    int sumGreen = 0;
    int count = 0;

    // I might need to make a temp image which i retrun at the end. So that I can get the original color from each pixel.
    for (int i = 0; i < height; i++) // x axis
    {
        for (int j = 0; j < width; j++) // y axis
        {
            // resets variables
            sumRed = 0;
            sumBlue = 0;
            sumGreen = 0;
            count = 0;

            // Go trough 9 boxes (3x3)
            for (int k = 0; k < 3; k++) // x axis blur (height)
            {
                for (int p = 0; p < 3; p++) // y axis blur (width)
                {
                    // Variables
                    int x = i-1+p;
                    int y = j-1+k;

                    // Checks if pixel is out of bounds
                    if (x < 0 || x > height-1 || y < 0 || y > width-1)
                    {
                        continue;
                    }
                    else
                    {
                        sumRed += image[x][y].rgbtRed;
                        sumBlue += image[x][y].rgbtBlue;
                        sumGreen += image[x][y].rgbtGreen;
                        count++;
                        printf("x = %d, y = %d. Redsum is %d\n", x, y, sumRed);


                    }

                }

            }

            copyImage[i][j].rgbtRed = round((float)sumRed/count);
            copyImage[i][j].rgbtBlue = round((float)sumBlue/count);
            copyImage[i][j].rgbtGreen = round((float)sumGreen/count);
            // I might need to have sum and count as floats. Let CS50 check figure that out later.
            // I need to find a way of not adding it directly to image. A simple for loop in the end would suffice, but lets try to avoid it. I also need to round the average.
                // That is simple. Just create a copy in
    }

    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copyImage[i][j].rgbtRed;
            image[i][j].rgbtBlue = copyImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copyImage[i][j].rgbtGreen;
        }
    }

    return;
}
int calculate(gX, gY)
{
    int sum = round(sqrt(((float)gX * (float)gX) + ((float)gY * (float)gY)));
    if (sum > 255)
    {
        return 255;
    }
    
    return sum;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Define copy variable
    RGBTRIPLE copyImage[height][width];

    // Variables i need

    // I might need to make a temp image which i retrun at the end. So that I can get the original color from each pixel.
    for (int i = 0; i < height; i++) // x axis
    {
        for (int j = 0; j < width; j++) // y axis
        {
            // Resets variables
            float xdiv[3] = {-1,-2,-1};
            float ydiv[3] = {-1,-2,-1};
            float GxSumRed = 0;
            float GxSumBlue = 0;
            float GxSumGreen = 0;
            float GySumRed = 0;
            float GySumBlue = 0;
            float GySumGreen = 0;
            for (int k = 0; k < 3; k++) // y axis (height)
            {
                for (int p = 0; p < 3; p++) // x axis (width)
                {
                    // Variables
                    int x = i-1+p;
                    int y = j-1+k;
                    // Checks if pixel is outside. If true it gives it a value of 0 for each colour.
                    if (x < 0 || x > height-1 || y < 0 || y > width-1)
                    {
                        if (k == 1)
                        {
                            xdiv[k] += 2;
                        }
                        else if (p == 1)
                        {
                            ydiv[p] += 2;                        
                        }
                        
                        else
                        {
                            xdiv[k] += 1;
                            ydiv[p] += 1;                   
                        }
                        continue;
                    }
                    else
                    {
                        // For Gx (x axis/k)
                        GxSumRed += (xdiv[k] * image[x][y].rgbtRed);
                        GxSumBlue += (xdiv[k] * image[x][y].rgbtBlue);
                        GxSumGreen += (xdiv[k] * image[x][y].rgbtGreen);

                        // checks if we are in the middle. i.e. I need 2 or 1. 
                        if (k == 1)
                        {
                            xdiv[k] += 2;
                        }
                        else
                        {
                            xdiv[k] += 1;
                        }
                        
                        // For Gy (y axis)
                        GySumRed += (ydiv[p] * image[x][y].rgbtRed);
                        GySumBlue += (ydiv[p] * image[x][y].rgbtBlue);
                        GySumGreen += (ydiv[p] * image[x][y].rgbtGreen);

                        // checks if we are in the middle. i.e. I need 2 or 1. 
                        if (p == 1)
                        {
                            ydiv[p] += 2;
                        }
                        else
                        {
                            ydiv[p] += 1;
                        }
                    }
                    
                }
                
            }
            copyImage[i][j].rgbtRed = calculate(GxSumRed, GySumRed);
            copyImage[i][j].rgbtGreen = calculate(GxSumGreen, GySumGreen);
            copyImage[i][j].rgbtBlue = calculate(GxSumBlue, GySumBlue);


            // I might need to have sum and count as floats. Let CS50 check figure that out later.
            // I need to find a way of not adding it directly to image. A simple for loop in the end would suffice, but lets try to avoid it. I also need to round the average.
                // That is simple. Just create a copy in
    }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = copyImage[i][j].rgbtRed;
            image[i][j].rgbtBlue = copyImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copyImage[i][j].rgbtGreen;
        }
    }
    
    return;
}