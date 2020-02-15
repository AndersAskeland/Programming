    #include <stdio.h>  
    #include <string.h>  
       
    int main()  
    {  
        char string[] = "abcde yf ";  
        int count;  
          
        printf("Duplicate characters in a given string: \n");  
        //Counts each character present in the string  
        for(int i = 0; i < strlen(string); i++) {  
            count = 1;  
            for(int j = i+1; j < strlen(string); j++) {  
                if(string[i] == string[j] && string[j] != ' ') // Checks if string j (i+1) is the same as i. Also removes the possibility of spaces are identified as duplicates
                {  
                    printf("Code contains duplicates\n");  
                    //Set string[j] to 0 to avoid printing visited character  
                    return 1;  
                }  
            }  
        }  
        printf("There are no duplicates\n");  
        return 0;  
    }  