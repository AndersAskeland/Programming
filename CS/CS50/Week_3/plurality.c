#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int voter_count = 0;
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usages: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name)) // Also calls function
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of elections
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int number = candidate_count;
    for (int i = 0; i < number; i++) // Ensures that there never is a null in candidates[i].name
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            printf("Match\n");
            return true;
        }
        continue;
    }
    printf("Not found\n");

    return false;

}

// Print the winner (or winners) of the election - This should be a bubble sort.
void print_winner(void)
{
    int swap_counter = -1;
    candidate temp;
    int number = candidate_count;
    while(swap_counter != 0)
    {
        swap_counter = 0;
        for(int i = 0; i < number-1; i++)
        {
            if(candidates[i].votes > candidates[i+1].votes)
            {
                swap_counter++;
                temp = candidates[i+1];
                candidates[i+1] = candidates[i];
                candidates[i] = temp;
            }
        }
    }

    if((candidates[number-1].votes == candidates[number-2].votes) && (candidates[number-1].votes == candidates[number-3].votes))
    {
        printf("%s\n%s\n%s\n", candidates[number-1].name, candidates[number-2].name, candidates[number-3].name);
    }
    else if(candidates[number-1].votes == candidates[number-2].votes)
    {
        printf("%s\n%s\n", candidates[number-1].name, candidates[number-2].name);
    }
    else
    {
        printf("%s\n", candidates[number-1].name);
    }
    return;
}

