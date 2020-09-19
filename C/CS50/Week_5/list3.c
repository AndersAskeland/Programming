// Implements a list of numbers with linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    char word[100];
    struct node *next;
}
node;

int main(void)
{
    // List of size 0
    node *list[1];

    // Add number to list
    node *n = malloc(sizeof(node));
    strcpy(n->word, "Test");
    n->next = NULL;
    list = n;

    // Add number to list
    n = malloc(sizeof(node));
    strcpy(n->word, "Test");
    n->next = NULL;
    list->next = n;

    // Add number to list
    n = malloc(sizeof(node));
    strcpy(n->word, "Test");    
    n->next = NULL;
    list->next->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%s\n", tmp->word);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
