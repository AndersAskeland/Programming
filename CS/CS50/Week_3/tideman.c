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
        printf("The ID for the top candiate for voter number %d is %d (name = %d)\n", i, ranks[0], ranks[0]);

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
            printf("Match for rank %d for candidate %s\n", rank+1, candidates[i]);
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
            printf("\nWe updated preferences for rank %d (i).\n Rank %d (i) had an ID of %d.\n Was compared to rank %d (j) with ID of %d\n The preference for this combination is now %d\n\n", i, i, ranks[i], j+1, ranks[j+1], preferences[(ranks[i])][(ranks[j+1])]);
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
        printf("Pair %d have %d as winner and %d as loser\n", pair_count - 1, pairs[pair_count-1].winner, pairs[pair_count-1].loser);
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
    
    printf("Highest strenght of victory is for ID %d compared to ID %d", pairs[0].winner, pairs[0].loser);
    return;

    // Might be completed - Try on a larger dataset
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

for (int i = 0; i < pair_count-1; i++)
{
    int winner = pairs[i].winner; // gets ID of winner of pair
    int loser = pairs[i].loser; // gets ID of loser of pair
        
    locked[winner][loser] = cycle(winner, loser, i);
    
    // if not - lock it.
}
 // last one - Should awoid loop - Think recurssion 



    // set locked to pairs[winner] and pairs [loser]
    // need to check if cycle is created each itteration - check if i'th itteration makes contact to first locked thingy
    return;
}


// Function for bool
bool cycle(winner, loser, i)
{
    int j = 0;
    bool check = true;
    
    
    // If j is below i / no more things to check - This is an out where it should significy that everything is True, and we have a loop.
    if (check == false)
    {
        return true
    }
    
    if (j < 1)
    {
        return false
    }

    if (locked[winner][loser] == true)
    {
        return true
    }
    
    for (int j = 0; j < pair_count; j++)
    {
        bool check = 
    }
}


// Print the winner of the election
void print_winner(void)
{
    int highestTrue = 0;
    double scores[MAX] = {0};

    for (int i = 0; i < pair_count; i++) // the locked array i and j should correspond to candidate
    {
        for (int j = 0; j < pair_count; j++)
        {
        if (locked[i][j] == true)
            {
                scores[i]++;
                if (scores[i] > highestTrue)  // sees if it is above
                {
                    highestTrue = locked[i][i];
                }
                
            }
        }
    }
    printf("The winner is %s\n", candidates[highestTrue]);
    // Two loops that run until it finds one that has 

    // might need to check whom is best if we have candidate number above 3
    return;
}

