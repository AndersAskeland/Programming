# Packages
from sys import argv, exit
import csv
from cs50 import SQL

## Check that at least 2 command line arguments
if len(argv) != 2:
    print("ERROR: You did not provide the correct number of command line arguments!")
    exit(1)

# Open db - I dont need to create it myself 
db = SQL("sqlite:///students.db")

# Open CSV
with open(argv[1]) as file:
    reader = csv.reader(file)

    # Loop over each row
    for counter, row in enumerate(reader):
        
        # Skips first column
        if counter == 0:
            continue

        # Checks if three names
        if len(row[0].split()) == 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", row[0].split()[0], row[0].split()[1], row[0].split()[2], row[1], row[2]) 

        # Checks if two names
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", row[0].split()[0], None, row[0].split()[1], row[1], row[2]) 



# Open CSV file
## csv.DictReader or csv.reader
# Use spit on name string


# For each row, parse name
# For each row/loop. 1) spit name. 2) Check amount of names. 3) insert names into database. 4) insert house and last shit.

# Use db.execute to insert a row into the table

# %%
