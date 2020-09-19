#include <stdio.h>
#include <stdlib.h>

// Define structure
typedef struct node
{
    char word[3];
}
node;


// Function
int main(void)
{
    // Variables
    node table[3];
    char test[100];
    
    // Open file - Remember to close file
    FILE *file;
    file = fopen("/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small", "r");

    // read data
    if (file != 0) // Checks if file is open
    {
        while (!feof(file)) // Checks if finished with file.
        {
           fgets(test, 100, file);

           
        }
        
    }
    else
    {
        printf("Error opening file\n");
    }
    

    // Test print
    for (int i = 0; i < 4; i++)
    {
        printf("%c", test[i]);
    }
    fclose(file);
}