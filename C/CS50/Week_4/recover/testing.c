#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool

// Defined a struct with size of 8 bit/1 byte. Same as a char usually, but to make completly sure its good to do it this way.
typedef uint8_t  BYTE;

// Function prototypes
bool startJPG();
bool writeJPG();


// The size of functiion gives the size of a type of data in bytes.
int main(int argc, char *argv[])
{
    // define variables
    BYTE buffer[512] = {0};

    // Checks command line argument
    if (argc != 2)
    {
        printf("You must supply one command line argument for this program\n");
        return 1;
    }

    // open memory card
    FILE *mmCard = fopen(argv[1], "r");
    printf("The size of buffer is %lu bytes\n", sizeof(*buffer));

    // Check if memory card is opened
    if (!mmCard)
    {
        printf("File is not opened\n");
    }
    else
    {
        printf("File is opened\n");
    }

    // Repeat until end of card - maybe
    while (buffer)
    {
        // Reads 512 bytes into buffer/memory
        fread(&buffer, 512, sizeof(*buffer), mmCard);
        
        // If start of new JPEG
        if (startJPG(buffer[0], buffer[1], buffer[2], mmCard))
        {
            // If first JPEG
            if (/* condition */)
            {
                /* code */
            }
            // Create a new file
            else
            {
                /* code */
            }
        }
        // If its not start - Continue writing
        else
        {
            /* code */
        }
        
        
    }

    
    
    // Loop that goes trough each 512 byte of data // Now it works. Maybe, its better to have this loop inside the writeJPG loop. And just have a while startJPG is false out here to reach fist location.
    
    for (int i = 0; i < 100000000; i++) // I need a method to find size of file. Maybe better to have a while loop until file is empty. Or file IS TRUE/open. i.e. while(mmCard){}
    {
        fread(&buffer, 512, sizeof(*buffer), mmCard);

        // First startJPG
        if startJPG(buffer[0], buffer[1], buffer[2], mmCard)
        {
            // Open new JPEG file
            writeFunction.
        }
        else
        {
            continue; // Skips rest of loop.
        }
        
                    
    }    

    // File that Im working on right now.
    FILE *currentJPEG;
    

    fclose(mmCard);
}



// Function to check for start - semi complete, I need last condition. Work on later.
bool startJPG(a, b, c, mmCard)
{
    if (a == 0xff && b == 0xd8 && c == 0xff)    
    {
        printf("Maybe\n");
    }
    return 1;
}


// Function to write to thingy.
bool writeJPG()
{
    // if - check if curretly wrting - If yes. close and start new,

    // Start writing.

    // For each loop, check startJPG function. If true. Recurssion/writeJPG. 

    // I need to figure out how to know when the file is done.

}