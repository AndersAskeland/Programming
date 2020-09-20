#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// Prototypes
void generateList(char *n);
void printList();
unsigned int hash(const char *word);
unsigned int size(void);
bool check(const char *word);
bool unload(void);
bool load(const char *dictionary);



// Typedef
typedef struct node {
    char word[50];       // Word 
    struct node *next;   // Address 
}
node;

// Define
#define DICTIONARY "/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small"


// Create main list outside of main as I also use it in other functions
node *list[26];
int wordCount = 0;

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
    // Print list
    printList(1);
    int i = size();

    printf("List i %d words long!\n\n", i);


    check("A");
    check("cat");

    
    // Free list
    unload();
    return(0);
}


// Main function
int main(void)
{
    load(DICTIONARY);

    // Variables


    // Check return value of fopen

        // I could have used fgets to read to \n but then I would
        // need to read to \n and not \0. Example below

        // while(fgets(tmpWord, 50, file))
        // {
        //  generateList(tmpWord);
        //  wordCount++;
        // }

    
}








bool unload(void)
{
    for (int i = 1; i <= 26; i++)
    {
        printf("Looking at index; %c\n", (char)i + 96);
        while (list[i] != NULL)
        {
            printf("Free memory for word %s\n", list[i]->word);
            node *snake = list[i]->next;
            free(list[i]);
            list[i] = snake;
        }
    }
    return(false);
}


















bool check(const char *word)
{
    // Variables
    node *snake;

    // Find hash index
    int index = hash(word);
    
    // Make word input lower case // I could have just used strcasecmp, strncasecmp - compare two strings ignoring case
    char *tempWord = strdup(word); // make a copy

    unsigned char *tptr = (unsigned char *)tempWord;
    while(*tptr) 
    {
        *tptr = tolower(*tptr);
        tptr++;
    }

    // Copy back to word
    word = tempWord;

    // release copy
    free(tempWord);

    
    // Set snake location
    snake = list[index];

    while(snake != NULL)
    {
        printf("INPUT: %s\nDICTIONARY: %s\n", word, snake->word);
        if (strcmp(word, snake->word) == 0)
        {
            printf("MATCH\n\n");
            return(true);
        }
        snake = snake->next;
    }
    printf("Fail\n\n");
    return(false);
}















unsigned int size(void)
{
    return(wordCount);
}























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



void printList()
{
    // Variables
    node *snake;

    // Goes through array and prints
    for (int i = 1; i <= 26; i++)
    {
        // Start of linked list
        snake = list[i];

        // Debug.... Print array location
        printf("\nIn array %c\n", (char)i + 96);

        // Go trough linked list and print all words
        while(snake != NULL)
        {
            printf("Word: %s", snake->word);
            snake = snake->next;
        }
    } 
    // newline at end
    printf("\n");
}



// Simple hash function that finds index
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
