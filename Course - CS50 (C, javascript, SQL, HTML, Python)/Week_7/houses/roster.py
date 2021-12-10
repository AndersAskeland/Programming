#%%
# Just take the argument and place it into a SQL loop. Sorted based on first and middle name.
# Packages
from sys import argv, exit
import csv
from cs50 import SQL

# Command line argument
if len(argv) != 2:
    print("ERROR: You did not provide the correct number of command line arguments!")
    exit(1) 

# Open database
db = SQL("sqlite:///students.db")

dict_ = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? GROUP BY last, first", argv[1])

for list_ in dict_:
    for counter, row in enumerate(list_.values()):

        # Check if middle name is NULL
        if row is None:
            continue

        # Print name
        if counter < 2:
            print(row, end="")
            print(" ", end="")
        
        # Prints last name without space
        elif counter < 3:
            print(row, end="")
        
        # Print year
        else:
            print(f", born {row}")
