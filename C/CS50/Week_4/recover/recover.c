#include <stdio.h>
#include <stdlib.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // Define variables
    BYTE dataBuffer[512];

    // Checks command line argument
    if (argc != 2)
    {
        printf("You must supply one command line argument for this program\n");
        return 1;
    }

    // Open file
    FILE *mmCard = fopen(argv[1], "r"); // open in read mode

    // Checks if file can be opened
    if (!mmCard)
    {
        printf("File is not opened\n");
        return 1;
    }
    else
    {
        printf("File is opened\n");
    }

        fread(buffer, 512, 1, mmCard);


    // Look trough for beginning of JPEG file - First byte is 0xff, second 0xd8, third 0xff, forth 0xe*.
    // fread(dataBuffer, 512, 1, argv[1]);
     
    // check dataBuffer[0-2]

    // for (int i = 0; i < 10; i++)
    // {
    //     check dataBuffer[3] == 
    // }
    

//     // Open new JPEG file
//     // filename 00x.jpeg
//     sprintf(filename, "%03i.jpg", i)
//     file *img = fopen(filename, "w")
//     fwrite(data, size/bytes, number, outptr)



//     // Write 512 bytes chunks until a new JPEG is found.
// fread returns number of items. 

//     // Close and return to top.
//     // if at end, close and write new.

//     // Stop at end of file.
}


// Pseudocode
// open memory card
// repeat until end of cared 
//     read 512 bytes into buffer
//     if start of new jpeg
//         if first jpeg
//             break
//         else
//             close previous file and write
//     else
//         continue writing

//         fclose