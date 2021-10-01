def longest_consec(strarr, k):
    # Error handling
    if len(strarr) == 0 or k > len(strarr) or k <= 0:
        return("")
    
    # Variables
    max = 0
    word = ""
    
    # Find longest word and location
    for count in range(0, (len(strarr) + 1 - k)):
        # Create word
        for i in range(k):
            print(strarr[count + i])
            word += strarr[count + i]
            
        # Check if longest concat
        if len(word) > max:
            max = len(word)
            output = word
        
        # Reset word
        word = ""
    
    # Print

    print(output)
    

longest_consec(["ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"], 1)