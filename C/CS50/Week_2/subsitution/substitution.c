/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Take a encryption key from the command line and substitute this with an input - Creating ciphertext ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Load packages
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// function prototypes
int duplicates(char string[]);
int alp(char string[]);

// main function
int main(int argc, char *argv[1]) // Takes command line argument - Argc is lenght of input, argV is input
{
    // Creates variables
    char cypher_id[40]; // A integer to store the int of the cypher in
    char cypher_id_upper[40];
    char cypher_id_lower[40];
    char input[99];
    char output[40] = {0};
    char alphabet[40];
    char alphabet_upper[40];
    int diff[40] = {0};

    // Validates command line argument
    if (argc != 2) // Checks if there exists a commanbd line argument
    {
        printf("missing command-line argument\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) // Checks lenght of argv
    {
        printf("Command argument is not correct lenght\n");
        return 1;
    }
    else if (duplicates(argv[1]) != 0) // checks for duplicates
    {
        return 1;
    }
    else if (argc == 2) // Should always be 2 because
    {

    }
    else
    {
        printf("something is wrong\n"); // any other errors are checked here
        return 1;
    }


    // Store key in string
    for (int i = 0; i < 26; i++)
    {
        cypher_id[i] = (argv[1][i]);
        cypher_id_lower[i] = tolower(cypher_id[i]); // lower case
        cypher_id_upper[i] = toupper(cypher_id[i]); // upper case
    }

    // Checks if everything is alphabetic
    if (alp(cypher_id) != 0)
    {
        return 1;
    }

    // Asks for input - Probably need to add a do while loop here.

    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);

    // Creates alphabet and
    for (int k = 0; k < 26; k++) // Creates the alphabeth - upper and lower
    {
        alphabet[k] = 'a' + k; // I might need a null terminator
        alphabet_upper[k] = 'A' + k;
    }


    // Two loops that calculates output
    for (int a = 0; input[a] != '\0'; a++) // First loop using input
    {
        if (islower(input[a]) || input[a] == ' ' || input[a] == ',' || isdigit(input[a])) // checks if there is an lowercase
        {
            for (int b = 0; alphabet[b] != '\0'; b++) // match input with alphabeth
            {
                if (input[a] == alphabet[b] || input[a] == ',' || input[a] == ' ' || isdigit(input[a]))
                {
                    diff[a] = ((double)cypher_id_lower[b] - (double)alphabet[b]);
                    // Calculate output
                    if (input[a] == ' ' || input[a] == ',') // allows spaces
                    {
                        output[a] = (double)input[a];
                        break;
                    }
                    else if (isdigit(input[a])) // allows numbers
                    {
                        output[a] = (double)input[a];
                        break;
                    }

                    else if (diff > 0)
                    {
                        output[a] = (double)input[a] + (double)diff[a];
                        break;
                    }
                    else
                    {
                        output[a] = (double)input[a] - (double)diff[a];
                        break;
                    }
                }
            }
        }
        else if (isupper(input[a])) // uppercase
        {
            for (int b = 0; alphabet_upper[b] != '\0'; b++) // match input with alphabeth
            {
                if (input[a] == alphabet_upper[b] || input[a] == ' ')
                {
                    diff[a] = ((double)cypher_id_upper[b] - (double)alphabet_upper[b]);
                    // Calculate output

                    if (diff > 0)
                    {
                        output[a] = (double)input[a] + (double)diff[a];
                        break;
                    }
                    else
                    {
                        output[a] = (double)input[a] - (double)diff[a];
                        break;
                    }
                }
            }

        }
        // Add null character to end of string, so that program does not keep reading.
        output[a+1] = '\0';

    }

    // Prints output
    printf("ciphertext: %s\n", output);
    return 0;
}







/////////////////
/// Functions ///
/////////////////

// Checks if alphabetic
int alp(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isalpha(string[i]) == 0)
        {
            printf("key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    return 0;
}

// Checks for duplications
int duplicates(char string[])
{
// function - two loops
    for (int i = 0; i < (strlen(string)); i++)
    {
        for (int j = i + 1; j < (strlen(string)); j++) // lower to lower case
        {
            if (string[i] == string[j] && string[j] != ' ')
            {
                printf("Code contains duplicates\n");
                return 1;
                break;
            }
            else if (string[i] == (string[j] - 32))
            {
                printf("Code contains duplicates lower - upper\n"); // I could also just had made everything lower case in main
                return 1;
                break;
            }
            else if (string[i] == (string[j] + 32))
            {
                printf("Code contains duplicates upper - lower\n");
                return 1;
                break;
            }
        }
    }
    return 0;
}
