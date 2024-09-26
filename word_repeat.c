/***
Description: In this program, the user will input a file name consisting of a variety of words, some of which are repeated 
words. The program will find these words that are repeated twice and write them to a file named "output.txt". This program 
basically organized the file inputed by the user by reading it, storing it into an array, using that array as a pointer in 
another function that sorts it, finding where it is repeated twice.
 ***/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// this is the function that will find out whether the word give is repeated or not
int is_square(char * word);

int main() {
    
    // to make sure the file name is no longer than 100 characters (excluding the .txt)
    char user_file_name[104];
    
    printf("Enter file name: ");
    scanf("%s", user_file_name);
    
    FILE *pFile;
    
    // opening the user-inputed file to read its contents
    pFile = fopen(user_file_name, "r");
    
    // initializing some variables needed for the while loop below
    char file_contents[MAX_LEN];
    int value_of_given_word;
    
    FILE *output_file;
    
    // opening another file to write the returned value values of the function below
    output_file = fopen("output.txt", "w");
    
    // gets the content of the file through the array
    while (fgets(file_contents, MAX_LEN, pFile)) {
        value_of_given_word = is_square(file_contents);
        
        // if the return value of the function below is == 1, then it will be writen to the output file
        if (value_of_given_word == 1)
            fprintf(output_file, "%s", file_contents);
    }
    
    // good practice to close files when done using them
    fclose(pFile);
    fclose(output_file);
    
    return 0;
}

int is_square(char * word) {

    // because the strlen function gives us the length of a string with its null character, I -1 at the end to give the strings actual value
    int length_of_word = strlen(word)-1;
    
    // to check if the string is even or odd
    if ((length_of_word)%2 == 0) {
        
        // now to check each letter of the string, it will just keep looping until it hits one of the return statements
        for (int i = 0; i < length_of_word; i++) {
            
            // this is to see if the word is repeating in the same string
            if (word[i] == word[(length_of_word/2)+i]) {
                
                // if the last letter and the last incremtented letter are the same after passing previous if statement, then return 1 and get written to output file
                if (length_of_word == (length_of_word/2)+i) return 1;
            }
            
            // to ensure the loop does not include the null character
            else if ((length_of_word/2)+i >= length_of_word) return 1;
            
            // if the word is even but not repeated
            else return 0;
        }
    }
    
    // if the word is odd, it will return 0 and ultimatly not get written to the output file
    return 0;

}
