##%
def array_diff(a, b):
    # Define new array/list
    output = []
    
    for value, count in enumerate(a):
        if value not in b[count]:
            print(b[count])

array_diff([1,2], [1])