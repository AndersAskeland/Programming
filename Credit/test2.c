            
#include <stdio.h>

main()
{ // define integers and ask for promt
    long long cc_number;
    long long temp_cc;
    long long even_cc = 0;
    long long odd_cc = 0;
    int checksum = 0;
    int amex = 0;
    int visa = 0;
    int mastercard = 0;
    int aboveten = 0;

        do // This says that the scanf cannot recieve anything below 0
    {  // Asks for a promt - Size
	    printf("This is a credit card checker!\nEnter your credit card number: ");
	    scanf(" %lld", &cc_number);    
    }
    while (cc_number < 0 || cc_number > 9999999999999999);

printf("This is the number %lld", cc_number);
    
 while (cc_number > 0)
        {
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = (cc_number / 10);
            temp_cc = cc_number % 10;
            if ((temp_cc * 2) > 9)
            {
                aboveten = (temp_cc * 2);
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                aboveten = aboveten / 10;
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                cc_number = cc_number / 10;  
            }
            else
            {
                even_cc = even_cc + (temp_cc * 2);
                cc_number = cc_number / 10;
            }        
        }   
printf("Even_CC = %lld, ODD_CC = %lld\n", even_cc, odd_cc);
long long test;
test = 4003600000000014/10;
printf("%lld", test);
 
}    
            