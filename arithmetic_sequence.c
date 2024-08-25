/***
 Description: In this program, we use pointer arithmetic to find out if a sequence initiated by the user is an arithmetic sequence. That means that, as each index of the array increases, the value of the difference 
 between two values within the array must match. This must be the case for all numbers in the array. If true, and the sequence entered by user is arithmetic, then the main function will output 'yes', if not, it will
 output 'no'.
 ***/

#include <stdio.h>

// call to the function below
int is_arithmetic_sequence(int *sequence,  int n);

int main() {
    
    // this is asking the user for size and values of array
    int size;
    
    printf("Enter length of the sequence: ");
    scanf("%d", &size);
    
    int first_array[size];
    
    printf("Enter numbers of the sequence: ");
    for (int i=0; i<size; i++)
        scanf("%d", &first_array[i]);
    
    // make return value of other function equal to a variable in main function
    int result = is_arithmetic_sequence(first_array, size);
    
    // if result == 1, print yes, if result == 0, print no
    if (result) printf("yes");
    else printf("no");
    
    
    return 0;
}

int is_arithmetic_sequence(int *sequence,  int n) {
    //This function returns 1 if sequence is an arithmetic sequence, and returns 0 if not.
    
    int *p = sequence;
    
    // I chose to set the difference equal before hand for simplicity
    int difference = (*(p+1) - *p);
    
    for (p = &sequence[0]; (p+1) < &sequence[n]; p++) {
        
        if ((*(p+1) - *p) == difference) continue;
        
        else return 0;
    }
    
    return 1;
}
