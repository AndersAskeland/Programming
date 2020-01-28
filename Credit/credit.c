#include <stdio.h>

main()
{ // define integers and ask for promt
    long long cc_number;
    int temp_cc;
    int even_cc = 0;
    int odd_cc = 0;
//    int checksum = 0;
//    int amex = 0;
 //   int visa = 0;
 //   int mastercard = 0;


    do // This says that the scanf cannot recieve anything below 0
    {  // Asks for a promt - Size
	    printf("This is a credit card checker!\nEnter your credit card number: ");
	    scanf(" %lld", &cc_number);    
    }
    while (cc_number < 0 || cc_number > 9999999999999999)
   

    if ((cc_number % 2) = 0); // This will find the even numbers
    {
        do
        {
            temp_cc = cc_number % 10;
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = cc_number / 10;        
        }
        while (cc_number > 0);    }

    else // this takes the odd numbers
    {
        do
        {
            temp_cc = cc_number % 10;
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = cc_number / 10;        
        }
        while (cc_number > 0);    }
    
    {
        
     
        printf("Even CC 1 = %d\n", even_cc);
        printf("Odd CC 1 = %d\n", odd_cc);

    return 0;
}