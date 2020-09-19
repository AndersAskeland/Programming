#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128 
#define RSIZ 10 

// Get struct
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int main(void) 
{
    node *table = NULL; // word goes inside here
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;




    fptr = fopen("/Users/aaske/Programming (GitHub)/C/CS50/Week_5/speller/dictionaries/small", "r");
    while(fgets(word[i], sizeof(word), fptr)) 
	{
        word[i][strlen(word[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file is: \n");    
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", word[i]);
    }
    printf("\n");

    fclose(fptr);
    return 0;
}