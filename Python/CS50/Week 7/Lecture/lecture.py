#%%
# Program that analyses data from CSV example

import csv

counts = dict() # Gives me an empty dict. Can also use {}

## Counts most titles
with open("data.csv") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].lower()

        if title in counts:
            counts[title] += 1
        else:
            counts[title] = 1

def f(item):
    return(item[1])

# Lambda - A function used once. The below is the same as the f function
# Print 
for key, value in sorted(counts.items(), key=lambda item: item[1], reverse=True):
    print(key, value, sep=" | ")


""" 
How to go from CSV to relational database. CSV files are slow when they are large.
To open/create up a sqlite database use:
> sqlite3 favorites.db

Set it in mode csv
> .mode csv

Import data
> .import "csv file" favorites

Look at data.
> .schema

CRUD!
(C)reate - SQL: INSERT
(R)ead - SQL: SELECT
(U)pdate - SQL: UPDATE
(D)elete - SQL: DELETE

There is just a few dozen functions in C.




Now you created database
You can use sqlLite using the following
> SELECT title FROM favorites ORDER BY title;

Or 

> SELECT title, COUNT(title) AS n FROM favorites GROUP BY title ORDER BY n DESC;


"""