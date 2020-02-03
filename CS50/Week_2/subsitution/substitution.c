// A program to take a encryption key from the command line and substitute this with an input - Creating ciphertext
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[5]) // Takes command line argument - Argc is lenght of input, argV is input
{
    int cypher_id[5]; // A integer to store the int of the cypher in

// Checks command line argument authentisity
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    else if (argc == 2) // Should always be 2 because 
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }

// Get the int of each vector
for (int i = 0; argv[i] = '\0'; i++)
{
    cypher_id[i] = &(*argv[i]);
}
    printf("Cypher_ID = %d\n", cypher_id[0]);
    printf("Cypher_ID = %d\n", cypher_id[1]);
    printf("Cypher_ID = %d\n", cypher_id[2]);
    printf("Cypher_ID = %d\n", cypher_id[3]);
    printf("Cypher_ID = %d\n", cypher_id[4]);

// Changes normal characters to cypher
//or (int j = 0; argv[j] = '\0'; j++)
//{
    /* code */
// }


    
}