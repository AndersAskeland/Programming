#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct candidate
{
    char name[24];
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;
int voter_count;


// Function prototypes
bool vote(char name);
void print_winner(void);
char name[24];


int main(int argc, char *argv[])
{
// Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

// Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

// Asks for input - Number of voters
    printf("Number of voters: ");
	scanf(" %d", &voter_count);  

// Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        puts("Vote: ");
        fgets(name, 27,stdin);

        vote(name);  
        // Check for invalid vote
        if (!vote(candidates[i].name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}



// Functions
// Update vote totals given a new vote
bool vote(char name)
{
    int i = 0;
    while (name != candidates[i].name)
    {
        if (name == candidates[i].name)
        {
            candidates[i].votes += 1;
            return true;
        }
          
    }
    
    // Look for candidate called name - Itterate - Does this candidate name match "name" - Linear search
    // If canndidate found, update vote total
    // Return true - ELSE....
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Print names that has the most votes. - If tie - Two lines. - Linear search
    return;
}

