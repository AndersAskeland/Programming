def update(row):
    new_row = ""


    for i in range(0, (len(row) - 2)):        
            
        # B/G/R
        if ((row[i] != row[i+1]) and (row[i] != row[i+2]) and (row[i+1] != row[i+2])):
            new_row += row[i+1]
            print(row[i] + row[i + 1] + row[i + 2])

        # R/R/B
        elif ((row[i] == row[i+1]) and not (row[i+1] == row[i+2])):
            new_row += row[i+2]
            print(row[i] + row[i + 1] + row[i + 2])

        # B/R/R
        elif ((row[i+1] == row[i+2]) and not (row[i] == row[i+1])):
            new_row += row[i]
            print(row[i] + row[i + 1] + row[i + 2])
        
        # R/G/R
        elif ((row[i] != row[i+1]) and (row[i+2] != row[i+1])):
            new_row += row[i+2]
            print(row[i] + row[i + 1] + row[i + 2])
        
        # R/R/R
        else:
            new_row += row[i]
            print(row[i] + row[i + 1] + row[i + 2])

    # Return
    return(new_row)


def triangle(row):    
    # Im going to do some recurssion 
    
    # Check if only one color / base case
    if(len(row) == 1):
        return(row)
        
    # Create new list
    for i in range(len(row) - 2):
        row = update(row)
        if (len(row) == 2):
            print("Todo")
        elif (len(row) == 1):
            return(row)
        else:
            next
    return(row)

triangle("RRGBRGBGB")