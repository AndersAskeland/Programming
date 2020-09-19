#include <stdio.h>
#include <stdlib.h>

// Prototype
void draw(int n);


// Main
int main(void)
{
    // Variables
    int *height = malloc(sizeof(int));

    // Gets user input
    printf("Height: ");
    scanf(" %d", height);

    // Call function
    draw(*height);
}


void draw(int n)
{
    // Base case
    if (n == 0) 
    {
        return;
    }

    // Recurssion
    draw(n - 1);

    // Loop
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}