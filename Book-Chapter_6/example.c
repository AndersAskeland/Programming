// Example program form chapter 6
// Pairs three kids with their favorite superhero

#include <stdio.h>
#include <string.h>

main()
    {

        char kid1[12]; // defines a character "kid1" and creates a 12 bit array that it stores it to.
        // As the character array also holds a null zero "\" this string can hold 11 true characters
        char kid2[] ="Maddie"; // Creates a variable "kid2", and also stores the string maddie in it
        // This array can not contain more than 6 characters (7 with null zero)
        char kid3[7] = "Andrew";
        char hero1[] = "Batman"; // Doing it like this means that I must add my string to it while i define it. I cant go back
        // if i not use a special function "strcpy"
        char hero2 [34] = "Spiderman"; // Just some extra space in case
        char hero3 [25]; // Not yet defined

        // Add a string one array at a time

        kid1[0] = 'K'; // Use '' for characters as they take up less memory than string as there is no null zero needed
        kid1[1] = 'a';
        kid1[2] = 't';
        kid1[3] = 'i';
        kid1[4] = 'e';
        kid1[5] = '\0'; // A null zero in all its grace

        strcpy (hero3, "The Incredible hulk"); // Copies shit in in hero, which was undefined. Needs the <string.h> libary

        printf("%s\'s favorite hero is %s.\n", kid1, hero1);
        printf("%s\'s favorite hero is %s.\n", kid2, hero2);
        printf("%s\'s favorite hero is %s.\n", kid3, hero3);

        return 0;
           }

