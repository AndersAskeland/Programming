#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int i;
	int j;
	int rows;
	do
	{
		// Asks for a promt - Size
		rows = get_int("Height: ");
	}

	// Will run this prompt while n is bellow 1 - No characters etc
	while (rows < 1);

	// Loop - creates an integer i - Counts up till i is no longer below n (as given by get_int) - Each time add one to i
	for (i = 0; i < rows; i++)
	{
		// Loop - Counts up till J is no longer below i
		for (j = 0; j < i; j = j+0)
		{
			printf("# ");
		}
		// This changes line each time - We therefore get the shape
		printf("  \n");
	}
}

#include <stdio.h>
#include <cs50.h>

int main(void)
{
	// defines a integer names input - Can be used troughout code
	int input;

	{
		// Asks for height of pyramid and stores it as "input"
		input = get_int("Height: ");
	}

	// Says that input needs to be asked if input is below 1 or (||) above 23
	while(input < 1 || input > 20)

// Print function - Print this as long as this is true
	{{
		 // Starts a counter "i" where stuff repeats until this is true.
		 for (int i = 0; i < input; input++);
	 }
	 printf("#"); }
	printf("\n");
stop
}
