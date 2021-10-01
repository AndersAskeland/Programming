#include <stdio.h>

main()
{
    char topping[24];
    int slices;
    int month, day, year;
    float cost;

  printf("How much does a pizza cost in your area?\n");
   printf("Enter as $xx.xx\n"); // Floats can only store stuff like this - Problem with scanf.
    scanf(" %f", &cost);


    printf("What is your favorite one-word pizza topping?\n"); // Strings can not hold spaces when using scanf
    scanf(" %s", topping); // You dont need & when collecting a string
    

    printf("How many slices of %s pizza", topping);
    printf("can you eat in one sitting?\n");
    scanf(" %d", &slices);

    printf("What is today's date (enter in xx/xx/xx format).\n");
    scanf(" %d/%d/%d", &day, &month, &year); // You can ask for several things and store them like this.

    printf("\n\nWhy not treat yourself to dinner on %d/%d/%d.", day, month, year);
    printf("\nand have %d slices of %s pizza!\n", slices, topping);
    printf("It will only cost you $%.2f!\n\n\n", cost/8*slices); // Takes cost of one pizza, divied on 8 slices per pizza and multiplies the amout of slices you will eat

    return 0;
}