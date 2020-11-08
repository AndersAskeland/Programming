def update(row):
    new_row = ""
    for i in range(0, 4):        
            
        # B/G
        if (row[i] == "B" and row[i+1] =="G") or (row[i+1] == "B" and row[i] == "G"):
            new_row += "R"
            
        # R/G
        elif (row[i] == "R" and row[i+1] == "G") or (row[i+1] == "R" and row[i] == "G"):
            new_row += "B"

            
        # B/R
        elif (row[i] == "B" and row[i+1] == "R") or (row[i+1] == "B" and row[i] == "R"):
            new_row += "G"
        
        # Identical
        else:
            new_row += row[i]
    
    # Return
    return(new_row)


def triangle(row):    
    # Im going to do some recurssion 
    
    # Check if only one color / base case
    if(len(row) == 1):
        return(row)
        
    # Create new list
    for i in range(len(row) - 1):
        row = update(row)
    return(row)

triangle("RBRG")



