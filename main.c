#include <stdio.h>
#include <string.h>
#include "input.h"
#include "recommendation.h"

//The array containing the name of all users
char users[6][80];
//Friends for User 1
char friendsUser1[4][80];
//Friends for User 2
char friendsUser2[4][80];
//Friends for User 3
char friendsUser3[4][80];
//Friends for User 4
char friendsUser4[4][80];
//Friends for User 5
char friendsUser5[4][80];
//Friends for User 6
char friendsUser6[4][80];

//The total number of Facebook users (Note it can be less than 6)
int numOfUsers = 0;
//The total number of friends for each user (Note that less than 4 friends can be provided for each facebook user)
int numFriendsPerUser[6];
//This stores all possible friend suggestions for a user
char friendsSuggestions[5][80];
int numFriendsOfSuggestions[5];

//This functions gets input for all users and their respective friends
int inputFacebookUsers();

// This function prints all users in a neat format
void printAllUsers(void);

/*
 * This function gets the respective user and populate friendsSuggestions and numFriendsOfSuggestions with friends suggestions
 * and returns the number of recommendations. Uses populate arrays to populate friend suggestions.
 */
int getUserAndPopulate(int n);

int main(void) {

    // invoke here the function to provide users as input
    numOfUsers = inputFacebookUsers();
    printf("%d Facebook users have been provided as input.\n", numOfUsers);
    //print all the users in a neat format
    printAllUsers();
    //gets input for selected user
    int selection;
    scanf("%d", &selection);
    //keep looping till valid input is entered, assuming there is at least one user
    while (selection < 1 || selection > numOfUsers) {
        printAllUsers();
        scanf("%d", &selection);
    }

    selection--; //decrease selection by one because arrays starts from 0 (not 1)
    //stores the no. of recommendation and populate the recommendation arrays
    int numberOfRecommendations = getUserAndPopulate(selection);
    //sorts the recommended users
    sortRecommendations(numberOfRecommendations, friendsSuggestions, numFriendsOfSuggestions);
    //prints the top 2 recommended users
    getSuggestion(users[selection], numberOfRecommendations, friendsSuggestions);

    return 0;

}

/*
 * This function asks the users to provide a list of facebook users.
 * For each facebook users it will be necessary to add a set of friends
 */
int inputFacebookUsers() {
    int i = 0;
    while (i < 6) {
        printf("%s", "Insert a Facebook User:\n");
        fgets(users[i], 80, stdin);
        //Checks whether if users[i] contains only new line, if so terminate loop
        if (users[i][0] == '\n')
            break;
        //get friends for each user
        switch (i) {
            case 0: numFriendsPerUser[i] = inputFriends(friendsUser1, users[i]);
                break;
            case 1: numFriendsPerUser[i] = inputFriends(friendsUser2, users[i]);
                break;
            case 2: numFriendsPerUser[i] = inputFriends(friendsUser3, users[i]);
                break;
            case 3: numFriendsPerUser[i] = inputFriends(friendsUser4, users[i]);
                break;
            case 4: numFriendsPerUser[i] = inputFriends(friendsUser5, users[i]);
                break;
            case 5: numFriendsPerUser[i] = inputFriends(friendsUser6, users[i]);
            default:
                break;
        }
        i++;
    }
    return i;
}
// This function prints all users in a neat format

void printAllUsers(void) {
    printf("Input the Facebook user to which you want to provide friends suggestions:\n");
    for (int i = 0; i < numOfUsers; i++) {
        printf("   (%d) %s\n", i + 1, users[i]);
    }
}

/*
 * This function gets the respective user and populate friendsSuggestions and numFriendsOfSuggestions with friends suggestions
 * and returns the number of recommendations. Uses populate arrays to populate friend suggestions.
 */
int getUserAndPopulate(int n) {
    int recommendation = 0; //stores the total number of recommendation
    switch (n) {
        case 0:
            recommendation = populateArrays(numOfUsers, n, friendsUser1, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        case 1:
            recommendation = populateArrays(numOfUsers, n, friendsUser2, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        case 2:
            recommendation = populateArrays(numOfUsers, n, friendsUser3, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        case 3:
            recommendation = populateArrays(numOfUsers, n, friendsUser4, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        case 4:
            recommendation = populateArrays(numOfUsers, n, friendsUser5, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        case 5:
            recommendation = populateArrays(numOfUsers, n, friendsUser6, users, numFriendsPerUser, friendsSuggestions, numFriendsOfSuggestions);
            break;
        default:
            break;
    };
    return recommendation;
}
