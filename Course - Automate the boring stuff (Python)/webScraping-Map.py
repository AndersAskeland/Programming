import webbrowser, sys

sys.argv # Allows command line arugments.

# Check if command line arguments are passed.

if len(sys.argv) > 1:
    address = " ".join(sys.argv[1:])
    webbrowser.open('https://www.google.com/maps/place/' + address)
else:
    print('I need a address in the argument')


