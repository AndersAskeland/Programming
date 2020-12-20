import csv

# Make file 
with open("title.basics.tsv", "r") as titles:
    reader = csv.DictReader(titles, delimiter = "\t")

    with open("shows1.csv", "w") as shows:
        writer = csv.writer(shows)

        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"]) # Make header

        for row in reader:
            if row["startYear"] == "\\N":
                continue

            year = int(row["startYear"])
            
            if year >= 1970:
                continue

            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
                writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]]) # Read over tsv and print

for i in range(1,5):
    print(i)