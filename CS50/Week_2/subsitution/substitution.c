// A program to take a encryption key from the command line and substitute this with an input - Creating ciphertext
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) // Takes command line argument
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
    }
    else if (argc == 2) // Should always be 2 because 
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
    return 0;
}