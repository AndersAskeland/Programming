#include <stdio.h>

main()
{ // define integers and ask for promt
    long long cc_number;
    int temp_cc;
    int even_cc = 0;
    int odd_cc = 0;
    int checksum = 0;
    int amex = 0;
    int visa = 0;
    int mastercard = 0;


    do // This says that the scanf cannot recieve anything below 0
    {  // Asks for a promt - Size
	    printf("This is a credit card checker!\nEnter your credit card number: ");
	    scanf(" %d", &cc_number);    
    }
    while (cc_number < 0 || cc_number > 9999999999999999);

do
{   
if (((cc_number % 2) == 0 && cc_number > 99)) // This takes the even numbers
    {
        while (cc_number > 99)
        {
            temp_cc = cc_number % 10;
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = cc_number / 10;        
        }
    }
else if ((((cc_number % 1) == 0 && cc_number > 99))) // this takes the odd numbers
    {
        while (cc_number > 99)
        {
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = cc_number / 10;
            temp_cc = cc_number % 10;
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;        
        }    
    }
    else if (cc_number < 10) // This defines it as a visa
    {
        visa = 1;
    }
    
    else if (cc_number >30 || cc_number < 40)
    {
        amex = 1;
    }
    else if (cc_number >40 || cc_number < 60)
    {
        mastercard = 1;
    }
    else
    {
        while (cc_number > 0)
        {
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = cc_number / 10;
            temp_cc = cc_number % 10;
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;        
        }    
    }
}
while (cc_number > 0);

checksum = even_cc + odd_cc;
        printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d\n", amex, visa, mastercard, checksum);

//if ((checksum % 10) == 0)
//{
//checksum = 1;
//}

        
     
        printf("Even CC 1 = %d\n", even_cc);
        printf("Odd CC 1 = %d\n", odd_cc);

    return 0;
}