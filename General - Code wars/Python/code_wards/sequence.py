def solution(args):
    # Variables
    output = ""
    i = 0

    # Itterate over all values
    for item in args:    
        
        # Check if on last two values
        if i >= (len(args) - 2):
            output += str(args[i])
            i += 1
        # Check if value is same as before. If it is concatenate
        elif (args[i] + 1) == (args[i + 1]) and (args[i] + 2) == (args[i + 2]): 
            # Set i as j
            j = i

            # Go over until alone
            while (args[j] + 1) == (args[j + 1]):
                j += 1    

                # Check if at end        
                if j >= (len(args) - 1):
                    break

            # Save
            output += str(args[i]) + "-" + str(args[j])
            
            # Change index
            i = j + 1
        # Check if alone
        else:
            output += str(args[i])
            i += 1
        
        # Check if done
        if i >= len(args):
            break

        # Add a comma
        output += ","
    return(output)

solution([-73,-70,-67,-65,-62,-60,-59,-58,-57,-54,-52,-49,-46,-44,-41,-38,-35,-33,-31,-28,-25,-24])