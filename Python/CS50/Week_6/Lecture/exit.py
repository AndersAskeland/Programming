### Exit ###
from sys import argv, exit

if len(argv) != 2:
    print("Missing command-line argument")
    exit(1) # Same as return in C
print(f"hello, {argv[1]}")