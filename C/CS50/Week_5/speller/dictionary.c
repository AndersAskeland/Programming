// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Prototypes
void generateList(char *n);


// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *list[26];  // Change this to alphabet
int wordCount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Variables
    node *snake;

    // Find hash index
    int index = hash(word);

    // Make word input lower case // I could have just used strcasecmp, strncasecmp - compare two strings ignoring case


    // Set snake location
    snake = list[index];

    while(snake != NULL)
    {
        if (strcasecmp(word, snake->word) == 0)
        {
            return(true);
        }
        snake = snake->next;
    }
    return(false);
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Takes the const string and turns it into a normal string.
    char *letters = (char*)word;

    // Converts first letter to lower
    char letter = tolower(letters[0]);

    // Sets ascii code
    int ascii = ((int)letter - 96);

    // Return
    return(ascii);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
   // Variables
    char tmpWord[50];

    // Load file and check open
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return(false);
    }

    // Loop over words // We can also use fscanf // fgets reads to newline. I dont know what is better.
    while (fscanf(file,"%s",tmpWord)==1)
    {
        generateList(tmpWord);
        wordCount++;
    }
    fclose(file);
    return(true);
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return(wordCount);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 1; i <= 26; i++)
    {
        while (list[i] != NULL)
        {
            node *snake = list[i]->next;
            free(list[i]);
            list[i] = snake;
        }
    }
    return(true);
}













/////// My own functions
// Adds it to the end of list.
// Stupid me could also just have
// added it to the front by pointing newNode to list->word
// and then list = newNode. Well, well.
void generateList (char *n)
{
    // Variables
    node *snake;
    int index = hash(n); // Gets index of first letter.

    // Check if first location
    if (list[index] == NULL)
    {
        // Variable
        list[index] = malloc(sizeof(node));

        // copy string in
        strcpy(list[index]->word, n);
        list[index]->next = NULL;
    }

    // End of list
    else
    {
        // Variable
        node *newNode = malloc(sizeof(node));

        // CHeck if enough RAM
        if (newNode == NULL)
        {
            printf("Not enough RAM\n");
        }

        // Add data to a node
        strcpy(newNode->word, n);
        newNode->next = NULL;

        // Set start of list
        snake = list[index];

        // Find end of list/last node
        while (snake != NULL && snake->next != NULL)
        {
            snake = snake->next;
        }

        // Insert at end of list
        snake->next = newNode;
    }
}