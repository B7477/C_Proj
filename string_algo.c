// When it prompts you to enter message, enter hatcatsatpat for a fun output!

// libraries and macro definitions
#include <stdio.h>
#include <string.h>
#define LENGTH 1000

void decrypt(char *input, char *output);

int main() {
    
    // setting input to char array length of 1000 characters (limit)
    char input[LENGTH+1];
    char output[LENGTH+1];
    
    printf("Enter message: ");
    scanf("%s", input);
    
    // call to function below
    decrypt(input, output);
    
    printf("Output: %s\n", output);
    
    return 0;
}

void decrypt(char *input, char *output) {
    
    // initializing char and count variable to increment through the character array
    char *p;
    char *q = output;
    int count = 0;
    
    for (p = input; *p != '\0'; p++) {
        
        // count++ is for skipping the proper amount of positions
        count++;
        
        for (int i = 0; i<count; i++) {
            
            *q = *p;
            q++;
            // add count to p so that it skips to the correct and new position
            p += count;
            
            // break to the next char in the array (input)
            break;
        }
    }
    
    *q = '\0';
}
