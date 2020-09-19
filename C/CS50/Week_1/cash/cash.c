#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototype
int calculate(float dollars);
float input(void);

int main(void)
{
    // Variables
    float *change = malloc(sizeof(float));
    int *count = malloc(sizeof(int));

    // Get input
    *change = input();

    // Calculate change
    *count = calculate(*change);

    // Print
    printf("%d\n", *count);
}




float input(void)
{
    // Variables
    float *input = malloc(sizeof(float));
    char term;

    do
    {
        printf("Change owed: ");
    }
    while ((scanf("%f%c", input, &term) != 2 || term != '\n') || *input < 0);

    return(*input);
}


int calculate(float dollars)
{
    // Variables
    int count = 0;

    // Convert to cents
    int cents = round(dollars * 100);

    // Calculate 25 cents
    while (cents >= 25)
    {
        cents = cents - 25;
        count++;
    }

    // Calculates 10 cents
    while (cents >= 10)
    {
        cents = cents - 10;
        count++;
    }

    // Calculates 5 cents
    while (cents >= 5)
    {
        cents = cents - 5;
        count++;
    }

    // Calculates 1 cents
    while (cents >= 1)
    {
        cents = cents - 1;
        count++;
    }
    return(count);
}
