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
    int aboveten = 0;

    do // This says that the scanf cannot recieve anything below 0
    {  // Asks for a promt - Size
        printf("This is a credit card checker!\nEnter your credit card number: ");
        scanf(" %lld", &cc_number);
    } while (cc_number < 0 || cc_number > 9999999999999999);

    if (((cc_number % 2) == 0 && cc_number > 99)) // This takes the even numbers
    {
        while (cc_number > 99)
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
    }
    else if ((((cc_number % 1) == 0 && cc_number > 99))) // this takes the odd numbers
    {
        while (cc_number > 100)
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
    }
    printf("cc number is now %lld\n", cc_number);
    if (cc_number == 37 || cc_number == 34) // This defines it as a visa
    {
        amex = 1;
    }

    else if (cc_number > 50 && cc_number < 56)
    {
        mastercard = 1;
    }
    else
    {
        visa = 1;
    }

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

    checksum = even_cc + odd_cc;
    printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);

    if ((checksum % 10) == 0)
    {
        checksum = 1;
    }
    else
    {
        checksum = 0;
    }

    if(checksum == 1 && amex == 1)
    {
        printf("AMEX\n");
    }  
    else if(checksum == 1 && mastercard == 1)
    {
        printf("Mastercard\n");
    }
    if(checksum == 1 && visa == 1)
    {
        printf("Visa");
    }
    else
    {
        printf("Invalid");
    }
    

}