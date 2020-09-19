#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[1])
{
    // Check input
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }

    // Variables
    char *plaintext = malloc(sizeof(char)*100);
    int input = atoi(argv[1]);


    // User input
    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Create ciphertext of same length
    char *ciphertext = malloc(strlen(plaintext));

    // Encipher
    for (int i = 0; i < (strlen(plaintext) - 1); i++)
    {
        ciphertext[i] = (int)plaintext[i] + input;
    }

    // Print
    printf("Ciphertext: %s\n", ciphertext);

}