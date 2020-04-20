

                    // For Gx
                    GxSumRed += (-1 * image[x][y].rgbtRed) + (0 * image[i-0+k][j-1].rgbtRed) + (1 * image[i+1+k][j-1].rgbtRed) // x = - 1
                    GxSumRed += (-2 * image[x][y].rgbtRed) + (0 * image[i-0+k][j-1].rgbtRed) + (2 * image[i+1+k][j-1].rgbtRed) // x = 0
                    GxSumRed += (-1 * image[x][y].rgbtRed) + (0 * image[i-0+k][j-1].rgbtRed) + (1 * image[i+1][j-1].rgbtRed) // x = + 1
                    }


                    '

            image[i][j].rgbtRed = round(sqrt(pow(GxSumRed, 2)) + (pow(GySumRed, 2)));
            image[i][j].rgbtBlue = round(sqrt(pow(GxSumBlue, 2)) + (pow(GySumBlue, 2)));
            image[i][j].rgbtGreen = round(sqrt(pow(GxSumGreen, 2)) + (pow(GySumGreen, 2)));'