#include <stdio.h>

main()
{
	int i;
	int j;
	int rows;
	
    do // This says that the scanf cannot recieve anything below 0

    {
        // Asks for a promt - Size
		printf("Height: ");
		scanf(" %d", &rows);    
    } 
    
    	while (rows < 1 ); // Do the above as long as rows is below 1

// This creates a loop where 1 is added to i as long as i is bellow rows
    for (i = 0; i < rows; i++)
    {
        // Inside of this loop J will start counting, and counting based on i

        for (j = 0; j < i; j++)
            { 
            printf("#"); // Each time j cycles its one less # to print.
            }
            printf("\n");
    }
    return 0;
}
    
    

