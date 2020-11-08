
## With recurssion
def triangle(row):    
    # Im going to do some recurssion
   # Reset new row
    new_row = ""   
    
    # Check if only one color / base case
    if(len(row) == 1):
        return(str(row)) 
  
    # Go over and create new loop skipping over two
    for i in range(0, (len(row) - 1)):        
            
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
    

    # Check if at end
    if(len(new_row) == 1):
        return(str(new_row))
    else:
        # Recursion
        triangle(new_row)
            