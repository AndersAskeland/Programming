#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    char word[50];
    struct node *next;
}
node;

int main(void)
{
    // Variables
    FILE *file = NULL; 
    node *list;
    char tmpWord[50];
    int i = 0;

    // Open dictionary
    file = fopen("/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small", "r");

    node *newNode = malloc(sizeof(node)); // The size of word is defined in typedef
    
    while(fgets(tmpWord, 50, file))
    {
        strcpy(newNode->word, tmpWord);
        newNode->next = NULL;

        while(list->next == NULL)
        {
            list->next = newNode;
        }
        i++;
    }


Keep a count for where in the list we are.

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%s\n", tmp->word);
    }




    
    fgets(tmpWord, 50, file);

    strcpy(n->word, tmpWord);

    printf("Word is: %s\n", n -> word);
}


