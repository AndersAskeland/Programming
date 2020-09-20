from cs50 import get_int


## Check input
while True:
    height = get_int("Height: ")
    if height > 0 and height <= 8:
        break    


## Hashes
for i in range(height):
    for k in range(height - (i+1)):
        print(' ', end = "")
    for j in range(i+1):
        print("#", end = "")
    print("  ", end = "")
    for j in range(i+1):
        print("#", end = "")
    print("\n", end= "")


