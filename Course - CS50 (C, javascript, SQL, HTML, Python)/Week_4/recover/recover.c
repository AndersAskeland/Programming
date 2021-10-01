#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool

// Defined a struct with size of 8 bit/1 byte. Same as a char usually, but to make completly sure its good to do it this way.
typedef uint8_t BYTE;

// Function prototypes

// The size of functiion gives the size of a type of data in bytes.
int main(int argc, char *argv[])
{
    // define variables
    BYTE *buffer = malloc(512 * sizeof(BYTE)); // It would probably be a good idea to free this memory at some point, but I dont fully understand. I actually dont need malloc for this to work
    int filenr = 0;
    char filename[10];
    FILE *img = NULL; // I need to define it here if I want to use it all places in my loop.

    // Checks command line argument is provided
    if (argc != 2)
    {
        printf("You must supply one command line argument for this program\n");
        return 1;
    }

    // open memory card
    FILE *mmCard = fopen(argv[1], "r");

    // Check if memory card is opened
    if (!mmCard)
    {
        printf("File is not opened\n");
        return 2; // Exit with return code 2.
    }
    else
    {
        printf("File is opened\n");
    }

    // Checks EOF and read to buffer. Will continue until it reach EOF
    while(fread(buffer, 512, sizeof(*buffer), mmCard) == 1) // I read in 8 bit chunks. However, I need to write to file in 1 bit chunks.
    {
        // Checks if its start of file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            printf("I found one start region\n");
            // Closes old file and itterates filenr if we are past first itteration (i.e. img file is opened)
            if (img != NULL)
            {
                fclose(img);
                filenr++;
            }

            // Creates a filename
            sprintf(filename, "%03d.jpg", filenr);

            // Create new file
            img = fopen(filename, "w");

            // Write to file
            fwrite(buffer, 512, 1, img);
            printf("\n\nWriting first part for file %d\n", filenr);

        }
        // Continue writing if a file is opened.
        else if (img != NULL)
        {
            printf("Writing next part\n");
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(mmCard);
}


