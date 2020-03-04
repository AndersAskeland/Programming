# This programs says hello and asks for name

print("Hello world!")
print("What is your name?")
myName = input() ## gets input - Needs to enter it using '

print("it is good to meet you," + myName)

print("The length of your name is:")
print(len(myName)) ## Gets lenght of string

print("What is your age?")
myage = input()

print("You will be " + str(int(myage) + 1) + " in a year") ## str is a string function int is a int function. This function conversts between the two. the int myage + 1 is converted to the string 27.