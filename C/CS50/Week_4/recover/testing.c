#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool

// Defined a struct with size of 8 bit/1 byte. Same as a char usually, but to make completly sure its good to do it this way.
typedef uint8_t  BYTE;

// Function prototypes
bool startJPG();

// The size of functiion gives the size of a type of data in bytes.
int main(int argc, char *argv[])
{
    // define variables
    BYTE buffer[512] = {0};
    int filenr = 0;
    char filename;
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
    while(fread(buffer, 512, sizeof(*buffer), mmCard) == 1)
    {     
        // Checks if its start of file
        if (startJPG(buffer[0], buffer[1], buffer[2], mmCard))
        {
            // Closes old file and itterates filenr if we are past first itteration (i.e. img file is opened)
            if (img != NULL)
            {
                fclose(img);
                img = NULL;
                filenr++;
            }
            
            // Creates a filename
            sprintf(&filename, "%03d.jpg", filenr);
            
            // Create new file
            img = fopen(&filename, "w");

            // Write to file
            fwrite(buffer, 512, sizeof(buffer), img);
        }
        // Continue writing if a file is opened.
        else if (img != NULL)
        {
            fwrite(buffer, 512, sizeof(buffer), img);
        }
    }    

    fclose(mmCard);
}



// Function to check for start - semi complete, I need last condition. Work on later.
bool startJPG(a, b, c, mmCard)
{
    if (a == 0xff && b == 0xd8 && c == 0xff) // bitwise comparison for d  
    {
        return 1;
        printf("Maybe\n");
    }
    return 0;
}


