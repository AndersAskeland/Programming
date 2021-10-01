// Example program from chapter 5 in my C book
// This program lists three kids and their school needs, as well as where to buy the supplies

#include <stdio.h>

main()
    {
    // Sets up variables
    char firstInitial, middleInitial;
    int number_of_pencils;
    int number_of_notebooks;
    float pencils = 0.23; // Defined on same line as introduced
    float notebooks = 2.89;
    float lunchbox = 4.99;

    // Information for Kid (Variable still)

firstInitial = 'J';
middleInitial = 'R';

number_of_pencils = 100;
number_of_notebooks = 4;

printf("%c%c needs %d pencils, %d notebooks, and 1 lnuchbox\n", firstInitial, middleInitial, number_of_pencils, number_of_notebooks);
printf("The total cost is $%.2f\n\n", number_of_pencils*pencils + number_of_notebooks*notebooks + lunchbox);

return 0;
    }