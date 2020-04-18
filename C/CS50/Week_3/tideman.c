#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX] = {0}; // sets them all to zero

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle();

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");
printf("Preference table is %d\n", preferences[1][1]);
    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) // calls vote function - at the same time checks if invalid
            {
                printf("Invalid vote.\n");
                return 3;
            }

        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++) // Uses ranks as I want to loop it only for the number of possible ranks.
    {
        if (strcmp(name, candidates[i]) == 0) // Only saves stuff if it matches-
        {
            ranks[rank] = i; // Saves candidate ID as ranks (rank 0 is best candidate)
            return true;
        }
        continue;
    }
    return false;
}

// Update global preference variable, preferences given one voter's ranks - Should now work.
void record_preferences(int ranks[])
{
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0+k; j < candidate_count-1; j++)
        {
            preferences[(ranks[i])][(ranks[j+1])]++;
        }
    k++;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // I just need to add enough pairs - Dont really know how it works. I probably need two for loops. Should be done!
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0+k; j < candidate_count - 1; j++)
        { // something wrong in this function........ Seems to work now.
            if (preferences[i][j+1] > preferences[j+1][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j+1;
                pair_count++;
            }
            else if (preferences[i][j+1] < preferences[j+1][i])
            {
                pairs[pair_count].winner = j+1;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
        k++;
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int swap_counter = -1;
    pair temp;
    while (swap_counter != 0)
    {
        swap_counter = 0;
        for (int i = 0; i < pair_count-1; i++)
        {
            // Should check if strenght of victory is higher in one compared to other - Sorts to the left/desc
            if ((preferences[(pairs[i].winner)][(pairs[i].loser)] - preferences[(pairs[i].loser)][(pairs[i].winner)]) < (preferences[(pairs[i+1].winner)][(pairs[i+1].loser)] - preferences[(pairs[i+1].loser)][(pairs[i+1].winner)]) )
            {
                swap_counter++;
                temp = pairs[i+1];
                pairs[i+1] = pairs[i];
                pairs[i] = temp;
            }
        }
    }

    return;

    // Might be completed - Try on a larger dataset
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
// loocks two first pair as there can never be a circle.
    for (int i = 0; i < pair_count; i++)
    {
        printf("####### Cycle lock running for winner %s vs loser %s #######\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
        int winner = pairs[i].winner; // gets ID of winner of pair
        int loser = pairs[i].loser; // gets ID of loser of pair

        locked[winner][loser] = cycle(winner, loser, i);

    }
        return;
}


// Function for checking if there is a cycle.
bool cycle(winner, loser, n)
{
    // Base cases
    if (locked[loser][winner] == true) // Checks if there is a loop
    {
        return false;
    }

    else if (n < 1) // Triggers if its trough everything and there was no loop
    {
        return true;
    }

    // Recurssion
    for (int i = 0; i < pair_count-1; i++)
    {
        n--;
        if (locked[loser][i] == true)
        {
            n = n - 1;
            cycle(winner, i, n);
        }
            else if (n == 0) // Triggers if its trough everything and there was no loop
        {
            return true;
        }

    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    int count = candidate_count;
    int loser[MAX] = {0};
    int winner[MAX] = {0};

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
            {
                loser[j]++;
                winner[i]++;
            }

        }

    }
    for (int k = 0; k <= candidate_count; k++)
    {
        if (loser[k] == 0 && k <= candidate_count && winner[k] > 0)
        {
            printf("%s\n", candidates[k]);
        }

    }


    return;
}

