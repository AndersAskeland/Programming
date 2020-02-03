#include <stdio.h>

int main(void)
{
// Define values
    long long cc_number;
    long long cc_number_start;
    long long cc_number_first;
    int cc_number_lenght = 0;
    int temp_cc;
    int checksum;
    int even_cc;
    int odd_cc;
    int aboveten;
    int amex = 0;
    int visa = 0;
    int mastercard = 0;

// Gets user input 
    do 
    {  
	    printf("This is a credit card checker!\nEnter your credit card number: ");
	    scanf(" %lld", &cc_number);  // Asks for a promt - Size
    }
    while (cc_number < 0 || cc_number > 9999999999999999); // Only accept numbers within this range

// Prepares other variables 
    cc_number_start = cc_number;
    cc_number_first = cc_number;

// Calculates even and odds CC and counts
    while (cc_number != 0) // Checksum
    {
        temp_cc = cc_number % 10;
        odd_cc = odd_cc + temp_cc;
        cc_number /= 10;
        cc_number_lenght++; // count
        temp_cc = cc_number % 10;
        if (((temp_cc * 2) > 9) && (cc_number != 0)) // Resolves is even number is over 9
        {
            aboveten = (temp_cc * 2); // Gives me answer of tempt cc * 2 (always over 9)
            temp_cc = aboveten % 10;
            even_cc += temp_cc;
            aboveten /= 10;
            temp_cc = aboveten % 10;
            even_cc += aboveten;
            cc_number /= 10;
            cc_number_lenght++; // Count
  
        }
        else if (cc_number != 0)
        {
            even_cc = even_cc + (temp_cc * 2);
            cc_number /= 10;
            cc_number_lenght++; // count
        }        
    }
    
// Calculates first two digits
    while (cc_number_start > 99)
    {
        temp_cc = (cc_number_start % 10);
        printf("temp_cc = %d, cc_number = %lld\n", temp_cc, cc_number_start);
        cc_number_start /= 10;   
    }

// Calculates first digit
    while (cc_number_first > 9)
    {
        temp_cc = (cc_number_first % 10);
        printf("temp_cc = %d, cc_number = %lld\n", temp_cc, cc_number_first);
        cc_number_first /= 10;   
    }

// Checksum
checksum = even_cc + odd_cc;

    if ((checksum % 10) == 0)
    {
        checksum = 1;
    }
    else
    {
        checksum = 0;
    }

// Cardtype
    if ((cc_number_lenght == 16) && (cc_number_start > 50 && cc_number_start <56)) // This defines it as a mastercard
    {
        mastercard = 1;
    }
    
    else if ((cc_number_lenght == 15) && (cc_number_start == 34 || cc_number_start == 37)) // defines it as amex
    {
        amex = 1;
    }
    else if ((cc_number_lenght == 13 || cc_number_lenght == 16) && cc_number_first == 4) // defines it as visa
    {
        visa = 1;
    }
    printf("amex = %d", amex);

// compare all parameters and prints
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

printf("Even = %d, Odd = %d, lenght = %d and ccnumber = %lld,  first two digits = %lld, first digit = %lld \n", even_cc, odd_cc, cc_number_lenght, cc_number, cc_number_start, cc_number_first);
}