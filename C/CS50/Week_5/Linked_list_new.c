#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Prototypes
void generateList(char *n);
void printList();

// Typedef
typedef struct node {
    char word[50];       // Word 
    struct node *next;   // Address 
}
node;

// Create main list
node *list;

// Main function
int main(void)
{
    // Variables
    FILE *file = fopen("/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small", "r"); 
    char tmpWord[50];

    // Check return value of fopen
    if (file == NULL)
    {
        return(0);
    }
    
    // Loop over words // We can also use fscanf // fgets reads to newline. I dont know what is better.
    while(fgets(tmpWord, 50, file))
    {
        // Use hash function to see which hash list the data should go inside.
        // Hash function should return a index. Most likely the best way is just
        // to use an ASCII alphabet on a twolower first word. 

        // For example
        //    hash(word)
        //    {
        //    word = tolower(word);
        //    int ASCII = (int)word;
        //    ASCII = ASCII - 96; // a becomes 1
        //    return(ASCII);
        //    }
        //

        // Update generateList with a index location. Then it 
        // would become something line
        // list[index].

        generateList(tmpWord);
    }


    // Print list
    printList();

    // Free list
    while (list != NULL)
    {
        node *snake = list->next;
        free(list);
        list = snake;
    }
}


// Adds it to the end of list. 
// Stupid me could also just have
// added it to the front by pointing newNode to list->word
// and then list = newNode. Well, well.
void generateList (char *n)
{
    // Variables
    node *snake;

    // Check if first location
    if (list == NULL)
    {
        // Variable
        list = malloc(sizeof(node));
        
        // copy string in
        strcpy(list->word, n);
        list->next = NULL;
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
        snake = list;

        // Find end of list/last node
        while (snake != NULL && snake->next != NULL)
        {
            snake = snake->next;
        }

        // Insert at end of list
        snake->next = newNode;
    }
}

void printList ()
{
    // Variables
    node *snake;

    // Set start of list 
    snake = list;

    // Go trough and print
    while(snake != NULL)
    {
        printf("Word: %s\n", snake->word);
        snake = snake->next;
    }
}
