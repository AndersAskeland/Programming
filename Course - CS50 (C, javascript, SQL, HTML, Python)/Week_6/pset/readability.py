from cs50 import get_string
import re


## Input
def main():
    while True:
        text = get_string("Write some letters:\n")
        break    

    ## Letters
    letters = len(re.sub("[^a-zA-Z]", "", text))

    words = len(text.split())

    sentences = text.count(".") + text.count("!") + text.count("?")

    grade = calculate(letters, words, sentences)

    if grade > 2 or grade < 16:
        print(f"Grade {round(grade)}")
    elif grade < 2:
        print("Before grade 1")
    else:
        print("Grade 16+")
    print(f"Number of letters: {letters}.\nNumber of words: {words}.\nNumber of sentences:{sentences} ")



def calculate(letters, words, sentences):
    l = ((letters / (words)) * 100)
    s = ((sentences / (words)) * 100)
    print(f"l is {l}, while s is {s}")
    return((0.0588 * l) - (0.296 * s) - 15.8)


main()