// Example program that will ask users for input
#include <stdio.h>

main()
{
    // Sets up some variables
    char firstInitial;
    char lastInitial;
    int age;
    int favorite_number;

    printf("What letter does your first name begin with?\n");
    scanf(" %c", &firstInitial); // & means that it holds the answer as firstInitial
    // This should not be used when you ask for a string %s. It is because it is a pointer variable

    printf("What letter does your last name begin with?\n");
    scanf(" %c", &lastInitial);

    printf("How old are you?\n");
    scanf(" %d", &age); // the space before %d often helps the input work better - This is good habit.

    printf("What is your favorite number (integer only)?\n");
    scanf(" %d", &favorite_number);

    printf("\nYour initials are %c.%c. and you are %d years old", firstInitial, lastInitial, age);
    printf("\nYour favorite numver is %d.\n\n", favorite_number);

    return 0;
}