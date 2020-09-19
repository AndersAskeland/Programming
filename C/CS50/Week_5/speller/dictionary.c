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
node *table[N];  // Change this to alphabet

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // if word in dictionary file. Make all things lower. Return T if found.
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
    dictionary = fopen("/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small.txt")
    // open dictionary

    // For line in file, add line to dictionary.  Remember that there is a \n at end of each line.

    // return true

// Use strcpy

// If next is null store here.
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
    // Probably a function that can look at this. Potentially for loop that counts until NULL. Look at words file.
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Loop that frees all stuff.
    return false;
}
