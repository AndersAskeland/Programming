#include <stdio.h>

main()
{ // define integers and ask for promt
    long long original_cc_number;
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
        scanf(" %lld", &original_cc_number);
    } while (original_cc_number < 0 || original_cc_number > 9999999999999999);
cc_number=original_cc_number;


    if ((((cc_number % 2) == 0) && cc_number > 100)) // This takes the even numbers
    {
        while (cc_number > 111)
        {
            temp_cc = cc_number % 10;
            if (((temp_cc * 2) > 9) && cc_number > 100)
            {
                aboveten = (temp_cc * 2);
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                aboveten = aboveten / 10;
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                cc_number = cc_number / 10;
            }
            else if (cc_number > 111)
            {
                even_cc = even_cc + (temp_cc * 2);
                cc_number = cc_number / 10;
            }
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = (cc_number / 10);
            

        }
    }
    else // this takes the odd numbers
    {
        while (cc_number > 111)
        {
            temp_cc = cc_number % 10;
            odd_cc = odd_cc + temp_cc;
            cc_number = (cc_number / 10);
            temp_cc = cc_number % 10;
            if (((temp_cc * 2) > 9) && cc_number > 100)
            {
                aboveten = (temp_cc * 2);
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                aboveten = aboveten / 10;
                temp_cc = aboveten % 10;
                even_cc = even_cc + temp_cc;
                cc_number = cc_number / 10;
                    printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);


            }
            else if (cc_number > 111)
            {
                even_cc = even_cc + (temp_cc * 2);
                cc_number = cc_number / 10;
                    printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);


            }
        }
    }

    printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d, Original = %lld, cc number = %lld\n", amex, visa, mastercard, checksum, even_cc, odd_cc, original_cc_number, cc_number);

    if ((cc_number == 37 || cc_number == 34) && (original_cc_number > 000000000000000 && original_cc_number < 999999999999999)) // This defines it as a visa
    {
        amex = 1;
    }

    else if ((cc_number > 50 && cc_number < 56) && (original_cc_number > 0000000000000000 && original_cc_number < 9999999999999999))
    {
        mastercard = 1;
        
    }
   
    else if ((original_cc_number > 0000000000000000 && original_cc_number < 9999999999999999) && (original_cc_number > 0000000000000 && original_cc_number < 9999999999999))
    {
        visa = 1;
    }
    printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);


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
                printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);

        }
        else
        {
            even_cc = even_cc + (temp_cc * 2);
            cc_number = cc_number / 10;
                printf("Amex = %d, VISA = %d, Mastercard = %d, checksum = %d Even = %d, odd = %d\n", amex, visa, mastercard, checksum, even_cc, odd_cc);

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

    if (checksum == 1 && amex == 1)
    {
        printf("AMEX\n");
    }
    else if (checksum == 1 && mastercard == 1)
    {
        printf("MASTERCARD\n");
    }
    else if (checksum == 1 && visa == 1)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}