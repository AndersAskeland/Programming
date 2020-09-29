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
Sqlite is a lightweight sql server.

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

Datatypes in SQL

* blob
 - Binary raw data.
* Integer
 - smallint -
 - integer - 32 bit
 - bigint - 64 bit
* Real
 - real - 32 bit
 - double precition - 64 bit
* Numeric
 - Bool
 - Dates
 - time
 - timestamp
 - Numeric - super accurate
* Text
 - char(n)
 - varchar(n) - n = Number of chars per cell. Varchar gives upper bound
 - text 


Now you created database
You can use sqlLite using the following
> SELECT title FROM favorites ORDER BY title;

Or 

> SELECT title, COUNT(title) AS n FROM favorites GROUP BY title ORDER BY n DESC;


Example:

> SELECT COUNT(title) FROM favotrites WHERE title LIKE %office%;

> UPDATE table SET title = "The Office" WHERE title Like "%office";

> DELETE FROM favorites WHERE title = "Friends";

> 


Functions
* Distinct - removes dups
* Count
* Max
* Min
* where
* Like
* limit
* group by
* Join 

"""