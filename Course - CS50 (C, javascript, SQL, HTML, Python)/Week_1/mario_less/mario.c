#include <stdio.h>
#include <stdlib.h>

// Prototype
void draw(int n, int org);
int input(void);


// Main
int main(void)
{
    // Variables
    int *height = malloc(sizeof(int));

    // Gets user input
    height = input();

    // Call function
    draw(*height, *height);
}


void draw(int n, int org)
{
    // Base case
    if (n == 0)
    {
        return;
    }

    // Recurssion
    draw(n - 1, org);

    // Space loop
    for (int j = 0; j < (org - n); j++)
    {
        printf(" ");
    }

    // # loop
    for (int i = 0; i < n; i++)
    {

        printf("#");
    }
    printf("\n");
}

int input(void)
{
    // Variables
    int *input = malloc(sizeof(int));
    char term;

    do
    {
        printf("Height: ");
    }
    while ((scanf("%d%c", input, &term) != 2 || term != '\n') || (*input < 1 && *input > 9));

    return(*input);
}
