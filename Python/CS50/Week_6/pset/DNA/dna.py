# Package import
from sys import argv, exit
import csv
import re

def countRegex(data, compare):
    ## Computes stuff i need
    baseLength = len(compare)

    # Extract data
    regText = r"((?:" + re.escape(compare) + r")+)"
    reg = re.findall(regText, data)
    
    if reg == []:
        print("Empty")
    else:
        # Counts longest 
        longest = len(max(reg, key=len))
        return(longest/baseLength)


## Check that at least 2 command line arguments
if len(argv) != 3:
    print("ERROR: You did not provide the correct number of command line arguments!")
    exit(1)

# Open and store CSV file
database_csv = open(argv[1], 'r')
database = csv.DictReader(database_csv)

# Open and store txt file
sequence_txt = open(argv[2], 'r') 
sqeuence = sequence_txt.read()


# Calculate repeats
AGATC = round(countRegex(sqeuence, "AGATC"))
AATG = round(countRegex(sqeuence, "AATG"))
TATC = round(countRegex(sqeuence, "TATC"))

# Debug
print(f"AGAT is: {AGATC}")
print(f"AGAT is: {AATG}")
print(f"AGAT is: {TATC}")

# Compare
# Loop through list
for line in database:
    print(line["name"])
    print(line["AGATC"])
    print(line["AATG"])
    print(line["TATC"])



# Open file using "with" function. This automatically closes the file after indentation is done.
# with open((argv[1]), 'r') as database_csv:
    # Read to database variable into dictionary
    # database = csv.DictReader(database_csv)
    

# Loop through list
for line in database:
    print(line["name"])
    print(line["AGATC"])
    print(line["AATG"])    

    



# Dictionary for myself

# ## name = get_string("Name: ")
# number = get_string("Number: ")

# writer = csv.writer(file) 
# writer.writerow((name, number))

# file.close()

# ## If you do it like this you dont need to close file.
# with open("phonebook.csv", "a"):
#     writer = csv.writer(file) 
#     writer.writerow((name, number))