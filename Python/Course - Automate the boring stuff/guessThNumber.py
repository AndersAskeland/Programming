# This is a guess the number game.
import random
secretNumber = random.randint(1,20)

print("I am thinking about a number between 1 and 20.")

for guessesTaken in range(1,7):
    print("Take a guess")
    guess = int(input())

    if guess < secretNumber:
        print("Your guess is to low")
    elif guess > secretNumber:
        print("Your guess is to high")
    else:
        break

if guess == secretNumber:
    print("Correct. You guessed the number in " + str(guessesTaken)  + " tries")
else:
    print("Nopsydope, the number i was thinking of was " + str(secretNumber))

