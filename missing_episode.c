/***
 * Description: In this program, the user will input the amount of episodes are in a particular season of a show that they watch. The user enters the watched episodes and the output is the one episodes that was unwatched.
 ***/

// This is the library used in this code
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // the number of episodes in the season will be labeled as num_episodes
    int num_episodes;
    printf("Enter number of episodes: ");
    scanf("%d", &num_episodes);
    
    // Because we know that the user is missing one episode, the size of the array will be one less than num_episodes
    int size = num_episodes-1;
    int user_list[size];
    
    // here, sum is initialized to equal 0, and missing_episode is the value we are looking for
    int sum=0, missing_episode;
    printf("\nEpisodes Watched (Input Format: 1 2 3...): ");
    
    //this for loop will add the values entered by the user to an array add all of the values in the array up
    for (int i = 0; i < (num_episodes-1); i++) {
        scanf("%d", &user_list[i]);

        // here, if entered a value greater than number of total episodes, the program will print message and terminate
        if (user_list[i] > num_episodes) {
            printf("Invalid Input\n");
            exit(1);
        }
        sum = sum + user_list[i];
    }

    // the program will iterate through the loop checking for duplicates. If there are some, the program will print a message and terminate
    for (int p = 0; p < size-1; p++) {
        for (int q = p+1; q < size; q++) {
            if (user_list[p] == user_list[q]) {
                printf("Duplicate Value Entered\n");
                exit(1);
            }
        }
    }

    // this is a formula is basically subtracting the whole sum of the number 1 to n from the sum calculated from user_list, that way the value gives the missing number
    missing_episode = (num_episodes*(num_episodes+1))/2 - sum;
    printf("Missing episode: %d\n", missing_episode);

    return 0;
}


