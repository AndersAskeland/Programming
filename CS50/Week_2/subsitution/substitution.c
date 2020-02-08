// A program to take a encryption key from the command line and substitute this with an input - Creating ciphertext
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[1]) // Takes command line argument - Argc is lenght of input, argV is input
{
// Creates variables
    char cypher_id[27]; // A integer to store the int of the cypher in
    char cypher_id_upper[27];
    char input[27] = {0}; // Input from user to change
    char output[27] = {0};
    char alphabet[27];
    char alphabet_upper[27];
    int diff[27] = {0};
// Input is case sensitive - Key is case un!!




// Checks command line argument authentisity
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    else if (argc == 2) // Should always be 2 because 
    {
        printf("Here we go!!\n");
    }
    // Need something that checks for number of letters and that characters arent duplicated

    // you can make a for loop to check for duplicates array +1 each time

// Asks for input - Probably need to add a do while loop here.
    puts("What is your word?");
    fgets(input, 27,stdin);

    printf("My word = %s\n", input); // Debug  

// Creates alphabet and 
    for(int k = 0; k < 26; k++) // Creates the alphabeth - upper and lower
    {
        alphabet[k] = 'a' + k; // I might need a null terminator
        alphabet_upper[k] = 'A' + k;
    }


    for (int i = 0; i < 26; i++) // stores the cypher id in a new string array - From input
    {
        cypher_id[i] = (argv[1][i]);
    }
    printf("Cypher id lower is = %s\n", cypher_id);

// creates a cypther_id_upper
    for (int u = 0; cypher_id[u] != '\0'; u++)
    {
        cypher_id_upper[u] = toupper(cypher_id[u]);
    }
    printf("Cypher id upper is = %s\n", cypher_id_upper);

// Two loops that calculates output
    for (int a = 0; input[a] !='\0'; a++) // First loop using input
    {
        if(islower(input[a])) // checks if there is an lowercase
        {
            printf("Running lowercase itteration %d\n\n", a);
            for (int b = 0; alphabet[b] !='\0'; b++) // match input with alphabeth
            {
                if (input[a] == alphabet[b])
                {
                    diff[a] = ((double)cypher_id[b]-(double)alphabet[b]);
                    printf("%c is %d different from %c\n", cypher_id[b],diff[a] ,alphabet[b]);
                    // Calculate output
                    if (diff > 0)
                    {
                        output[a] = (double)input[a]+(double)diff[a];
                        printf("lower output= %c\n", output[a]);
                        break;                
                    }
                    else
                    {
                        output[a] = (double)input[a]-(double)diff[a];
                        printf("lower output= %c\n", output[a]);
                        break;                
                    }
                }                
            }
        }
        else if(isupper(input[a])) // uppercase
        {
            for (int b = 0; alphabet_upper[b] !='\0'; b++) // match input with alphabeth
            {
                if (input[a] == alphabet_upper[b])
                {
                    diff[a] = ((double)cypher_id_upper[b]-(double)alphabet_upper[b]);
                    printf("%c is %d different from %c\n", cypher_id_upper[b],diff[a] ,alphabet_upper[b]);
                    // Calculate output
                    if (diff > 0)
                    {
                        output[a] = (double)input[a]+(double)diff[a];
                        printf("output= %c\n", output[a]);
                        break;                
                    }
                    else
                    {
                        output[a] = (double)input[a]-(double)diff[a];
                        printf("output= %c\n", output[a]);
                        break;                
                    }                
                }        
            }
   
        }
        
    }

// Prints output
    printf("Output: %s\n", output);
    return 0;









/* 
    for (int y = 0; y < 26; y++) // Finds the difference of the cyper_id with the alpabeth
    {
        diff[y] = ((double)cypher_id[y]-(double)alphabet[y]);
        printf("%c is %d different from %c\n", cypher_id[y],diff[y] ,alphabet[y]);
    }
    
// Takes ID and adds the difference to it compared to alphabet
    for (int j = 0; input [j] != '\0'; j++)
    {
        if (diff[j] > 0)
        {
            output[j] = (double)input[j]+(double)diff[j];
            printf("output= %c\n", output[j]);
        }
        else
        {
            output[j] = (double)input[j]-(double)diff[j];
            printf("output= %c\n", output[j]);
        }       
    }


/* cypher_id[0] = argv[1][0];
cypher_id[1] = argv[1][1];
cypher_id[2] = argv[1][2];
cypher_id[3] = argv[1][3];
cypher_id[4] = argv[1][4]; */





    
} 