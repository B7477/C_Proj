/***
 Description: In this program, the main function will ask the user to input the number of students (size of array) and points of array (values of array), then, using the assign function and pointer arithmetic, 
 we will assign a value 1, 2, or 3 and store it in the empty team_assignment array, then use this array to printf the result so that the reader can see what the sorting was.
 ***/

#include <stdio.h>

// this is the function that will use pointer arithmetic to sort the student to there respective groups
void assign(int *points, int *team_assignment,  int n);

int main() {
    int size = 0;
    printf("Enter number of students: ");
    scanf("%d", &size);
    int points[size];
    // here, initialized the array and size of it from user input
    
    printf("Enter points for each student: ");
    for (int i=0; i<size; i++) {
        scanf("%d", &points[i]); }
    
    // this is an empty array that will soon be filled with the numbers 1,2,3
    int team_assignment[size];
    
    // call to void function below
    assign(points, team_assignment, size);
    
    printf("Beginner team: student ");
    for (int i = 0; i < size; i++) {
        if (team_assignment[i] == 1) {
            printf("%d ", i+1);
        } else continue;
    }
    
    printf("\nHonor team: student ");
    for (int i = 0; i < size; i++) {
        if (team_assignment[i] == 2) {
            printf("%d ", i+1);
        }
        else continue;
    }
    
    printf("\nExcellence team: student ");
    for (int i = 0; i < size; i++) {
        if (team_assignment[i] == 3) {
            printf("%d ", i+1);
        }
        else continue;
    }
    
    return 0;
}

void assign(int *points, int *team_assignment,  int n) {
    
    // assigned pointer variables to the first element of each array
    int *q = points;
    int *r = team_assignment;
    
    // the pointer q is pointing to the index of the array points, and then incrememnting the pointer (moving to next index) in next iteration
    for (q = &points[0]; q < &points[n]; q++) {
        
        // this is comparing the the value stored in the pointer
        if (*q <= 47) {
            // this will store the number in the respective array index, and increment the pointer to move to next index number
            *r = 1;
            r++;
        }
        else if (*q > 47 && *q <= 97){
            *r = 2;
            r++;
        }
        else {
            *r = 3;
            r++;
        }
    }

}
