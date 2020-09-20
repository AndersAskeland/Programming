from cs50 import get_int
import math
from sys import exit


## Get user input
def main():
    while True:
        cc_number = get_int("This is a credit card checker!\nEnter your credit card number: ")
        if cc_number > 1 and cc_number < 9999999999999999:
            break

    ## Determine if valid
    if (cc_calculator(cc_number) % 10 != 0):
        print("INVALID")
        exit(0)


    ## Find first two digets
    length = len(str(cc_number))

    if first_n_digits(cc_number, 2) in range(50, 56) and length == 16:
        print("MASTERCARD")
    elif first_n_digits(cc_number, 2) in [34, 37] and length == 15:
        print("AMEX")
    elif first_n_digits(cc_number, 1) == 4 and length in [13, 16]:
        print("VISA")
    else:
        print("I dont know")


def first_n_digits(cc, n):
    return(cc // 10 ** (int(math.log(cc, 10)) - n + 1))


def cc_calculator(cc):
    odd_cc = []
    even_cc = []


    while cc != 0:
        ## Odd numbers
        product = cc % 10
        odd_cc.append(product)

        ## Round down
        cc = math.floor(cc/10)

        ## Even numbers
        product = (cc % 10) * 2
        while product > 9:
            above_ten = product
            product = above_ten % 10
            even_cc.append(product)
            product = math.floor(above_ten/10)

        even_cc.append(product)

        ## Round down
        cc = math.floor(cc/10)


    return(sum(even_cc) + sum(odd_cc))
main()
