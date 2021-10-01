#include <stdio.h>

int main(void)
{
    // define integers and ask for promt
    int i;
    int j;
    int rows;
    int k;

    // This says that the scanf cannot recieve anything below 0
    do
    {
        // Asks for a promt - Size
        printf("This is a Mario Pyramid builder!\nEnter a number betwen 1-8: ");
        scanf(" %d", &rows);
    }
    while (rows < 1 || rows > 8); // Do the above as long as rows is bellow 1 or above 24




    // I LOOP - This creates a loop where 1 is added to i as long as i is below rows - Loops the entire bottom thing
    for (i = 1; i <= rows; i++)
    {
        // Loop K - Something that creates empty spaces it takes I - rows.
        for (k = 0; k < rows - i; k++)
        printf(" ");


        // LOOP J - Inside of this loop J will print # and change line each time it is looped by the above function
        for (j = 0; j < i; j++)
        printf("#"); // Each time j cycles its one less # to print
        printf("  "); // Creates the spaces inbetween!!
        // Loops as long as J is bellow I


        // LOOP J - creates the second part of the pyramid
        for (j = 0; j < i; j++)
        printf("#");
        printf("\n"); // When all above loops are done, go to new line - and go back to LOOP I.

    }
    return 0;
}