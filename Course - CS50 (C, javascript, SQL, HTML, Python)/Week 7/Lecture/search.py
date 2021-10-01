import csv
title = input("Title: ")

with open("shows2.csv", "r") as file:

    reader = csv.DictReader(file)

    for row in reader:
        if title == row["primaryTitle"]:
            print(row["primaryTitlee"], row["startYear"])