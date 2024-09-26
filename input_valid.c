/***
Description: In this code, the user will enter a set of characters, something like a user name, and the program will tell 
the user whether this input entered was valid or invalid. This will use a combination of array and pointer arithmetic to 
ensure the user is inputing valid arguments. 
 ***/

// These are the libraries
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // initialization of the variables needed later
    char *p;
    int is_valid = 0;
    
    // this is to catch the argument and make sure that it atleast has one usable argument
    if (argc < 2) {
        printf("invalid number of arguments");
        exit(-1);
    }

    // this incrementation is for the arguments that the user will input
    for (int i = 1; i < argc; i++) {
        
        // this incrementation is for each letter that is apart of the string (argument) the user inputed
        for (p = *(argv+i); *p != '\0'; p++) {
            
            // This is to make sure that the previous letter was acceptable
            if (is_valid == 1) {
                break;
            }
            
            // making sure if the current letter we are on is valid
            if((*p>='a' && *p<='z')||(*p>='0' && *p<='9')||(*p==' ')||(*p=='!')||(*p=='?')||(*p=='.')||(*p=='\n')) {

                is_valid = 0;
                
            } else {
                
                is_valid = 1;
                break;
            }
            
            
        }
        
        // to mark the end of a string
        *p = '\0';

    }
    
    if (is_valid == 0) printf("valid");
    else printf("invalid");
    
    return 0;
    
}
