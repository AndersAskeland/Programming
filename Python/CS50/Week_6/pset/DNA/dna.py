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
        print("No match")
        return(0)
    else:
        # Counts longest 
        longest = len(max(reg, key=len))
        return(longest/baseLength)

def checkDNA(sequence, database):
    dict = {}
    for i, key in enumerate(database.fieldnames):
        if key == "name":
            continue
        else:
            # Extract data using regular expressions
            regText = r"((?:" + re.escape(key) + r")+)" 
            reg = re.findall(regText, sequence)

            # Check input
            if reg == []:
                print("No match")
                exit(1)
            else:
                # save in dictionary
                dict[i] = (len(max(reg, key=len)))/(len(key))
                print(f"Sequence is; {dict[i]}")
                # list.append(((len(max(reg, key=len)))/(len(key))))
    # Return
    return(dict)    

def checkMatch(original, match):
    for i, key in enumerate(original):
        matchCount = 0
        for count, vector in enumerate(key.items()):
            if count == 0:
                name = vector[1]
                print(f"Looking at {vector[1]} which is on row: {i}")
                continue
            elif int(vector[1]) == int(round(match[count])):
                print(f"Original: {count}: {vector[1]}")
                print(f"Match: {round(match[count])}")
                print("There was a match")
                print(len(key))
                matchCount = matchCount + 1
                if matchCount == len(key) - 1:
                    print(f"There is a match for {name}")  
                    return(name)
            else:
                print(f"No match")
                continue
    print("No match final")
    exit(1)

   
            


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
extractedData = checkDNA(sqeuence, database)

print(f"Extracted: {extractedData}")
print(f"Database: {database}")

print(checkMatch(database, extractedData))


# compareInput(database, extractedData)
# # Loop trough extracteddata
# for count, line in enumerate(extractedData):
#     print(line)
    
# Loop through list


# for line in database:
#     print(line["name"])
#     print(line["AGATC"])
#     print(line["AATG"])
#     print(line["TATC"])



# Regex
# compareReg = r"('" + re.escape([key for key in compare.keys()][0]) + r"').+)"


# Open file using "with" function. This automatically closes the file after indentation is done.
# with open((argv[1]), 'r') as database_csv:
    # Read to database variable into dictionary
    # database = csv.DictReader(database_csv)


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




# def compareInput(original, compare):
#     print("Inside compare input function")
#     for data in original.fieldnames:
#         print(f"Data is: {original[data]}")


# def compareDict(key, original, compare):
#     for count2, line in enumerate(original):
#         print(f"Value for cnr: {count2} - {key} is: {line[key]}")

    
# %%
