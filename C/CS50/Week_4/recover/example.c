#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    char * jpg_filename = NULL;

    FILE *f = fopen("card.raw", "r");

    if (f == NULL)
    {
        return 1;
    }

    BYTE *buffer = malloc(512 * sizeof(BYTE));

    bool file_open = false; //flag indicating if a file is open 

    FILE *img = NULL;

    while (fread(buffer, 512, 1, f) == 1) // read continuously until the end of the file
    {
        fread(buffer, 512, 1, f);

        int jpg_count = 0;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //if it matches tha pattern of jpeg file
        {

            if (file_open == false)
            {

                jpg_count++;
                sprintf(jpg_filename, "%03i.jpg", jpg_count - 1);
                img = fopen("jpg_filename", "w");
                file_open = true; //set the flag to true indicating there is a file currently open
                fwrite(buffer, 512, 1, img);

            }
            else //a file is open, then we're at the start of another jpeg
            {

                fclose(img); //close the current one since it's finished

                // open up a new img file to write in the new data
                jpg_count++;
                sprintf(jpg_filename, "%03i.jpg", jpg_count - 1);
                img = fopen("jpg_filename", "w");
                fwrite(buffer, 512, 1, img);
            }
        }
        else// else the start of four bytes isn't a jpeg file
        {
            if (file_open)
            {
                //keeping writing to the same jpeg file with remaining bytes
                fwrite(buffer, 512, 1, img);
            }
            else
            {
                //if no file is open and this block isn't a start of jpeg
                continue;
            }
        }

    }
    fclose(f);
    fclose(img);
    free(buffer);
}