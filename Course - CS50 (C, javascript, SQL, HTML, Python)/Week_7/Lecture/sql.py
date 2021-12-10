# We can write SQL inside python
import csv
import cs50

# Create empty file
open("shows3.db", "w").close()

# Run som  SQL code to open in SQLite
db = cs50.SQL("sqlite:///shows3.db")

# Create table called shows 
db.execute("CREATE TABLE shows (tconst TEXT, primaryTitle TEXT, startYear NUMERIC, genres TEXT)") # db.executes runs sql.



with open("title.basics.tsv", "r") as titles:

    reader = csv.DictReader(titles, delimiter = "\t")

    for row in reader:
        if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
            if row["startYear"] != "\\N":

                startYear = int(row["startYear"])

                if startYear >= 1970:
                    tconst = row["tconst"]
                    primaryTitle = row["primaryTitle"]
                    genres = row["genres"]


                    db.execute("INSERT INTO shows(tconst, primaryTitle, startYear, genres) VALUES(?, ?, ?, ?)", tconst, primaryTitle, startYear, genres) 
                    
                    
                # The ? is the same as %s in C