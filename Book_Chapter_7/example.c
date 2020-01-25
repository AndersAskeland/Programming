// This is a program that uses the header_example h file

#include <stdio.h>
#include "header.h" // Using "" it will search the computer for the file
#include <string.h>

main()

{
    int age; // Creates the variable age
    char childname [14] = "Thomas";

    printf("\n%s have %d kinds. \n",FAMILY, KIDS);
    age = 11; // Defines the age as the string 11

    printf("The olderst, %s, is %d.\n", childname, age);
    
    strcpy(childname, "Christopher");
    age = 6;
    printf("The middle boy, %s, is %d.\n", childname, age);

    age = 3;
    strcpy(childname, "Benjamin");
    printf("The youngest, %s, is %d.\n", childname, age);
}