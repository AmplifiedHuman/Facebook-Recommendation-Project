#include <stdio.h>
#include <string.h>
#include "input.h"

/**
 * This method asks the user to provide as input the friends
 * of a Facebook user.
 *
 * Input:
 * friends, contain the names of friends provided as input
 *
 * Output:
 * Returns the number of friends provided as input. Note that
 * a user may decide to input less than 6 friends.
 */
int inputFriends(char friends[][80], char name[80]) {
    int i = 0;
    //removes new line from the user's name
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    puts("");
    while (i < 4) {
        printf("Enter friend %d for %s\n", i + 1, name); //uses i + 1 as i starts from 0
        fgets(friends[i], 80, stdin);
        if (friends[i][0] == '\n')
            break;
        //removes new line from the user's friend(s) name
        if (friends[i][strlen(friends[i]) - 1] == '\n') {
            friends[i][strlen(friends[i]) - 1] = '\0';
        }
        i++;
    }
    puts("");
    //returns total number of friends of selected user
    return i;
}
