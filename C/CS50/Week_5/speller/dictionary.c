// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // 1 - Open file
    ////// fopen and check if return value is NULL
    // 2 - read string from file
    /////// fscanf(file, "%s", word). Fscanf return EOF once at end of file. Repeat on each word in dictionary.
    /////// Usually loop to run. file = file pointer, s = read stinr, word = char array to read into
    // 3 - Create new node for each word
    ////// use malloc to allocate new memory. Check if malloc return null
    ///// Copy word into node (strcpy)
    // 4 - hash word
    ///// Use hash function. Takes string and return an index you can use.
    // 5 - Insert node into hash table
    /// Add new node to new list. set pointer in correct order.
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
