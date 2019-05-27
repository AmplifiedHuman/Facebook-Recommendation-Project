#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "recommendation.h"

/*
 * This function populate the selected user with possible friendsSuggestions, it fills
 * friendsSuggestions with the suggested names and also fills numFriendsOfSuggestions with
 * the friend count of each suggested friend.
 *
 * Input:
 * totalUsers - total number of users (max 6)
 * user - is the index of the current selected user
 * users - 2d array which contains the names of all users
 * friendList - 2d array which contains the friends of the selected user
 * numbernumFriendsPerUser - friend count of each user
 * friendSuggestions - 2d array which stores the names of the suggested friends
 * numFriendsOfSuggestions - stores the friend count of the suggested friends
 *
 * Output:
 * count - the total number of suggested friends
 */
int populateArrays(int totalUsers, int user, char friendList[][80], char users[][80], int numbernumFriendsPerUser[6], char friendsSuggestions[6][80], int numFriendsOfSuggestions[6]) {
    int count = 0;
    bool found; //use to keep track if the friends of the selected user is in the users array
    for (int i = 0; i < totalUsers; i++) {
        found = false;
        int j = 0;
        while ((j < numbernumFriendsPerUser[user]) && !found) {
            if (strcmp(users[i], friendList[j]) == 0) {
                found = true;
            }
            j++;
        }
        if (!found && (i != user)) { //if a user is not a friend of the current user, then store it as a recommendation
            strcpy(friendsSuggestions[count], users[i]);
            numFriendsOfSuggestions[count++] = numbernumFriendsPerUser[i];
        }
    }
    return count;
}

/* This function sorts users depending on the number of their friends (from the biggest to the smaller).
 * If 2 users have the same number of friends they will be sorted alphabetically.
 * When sorting according to the number of their friends, selection is used
 * for efficiency purposes.
 * When sorting alphabetically, insertion sort is used as the array is already partially
 * sorted (faster)
 *
 * Input:
 * users - Number of recommended users
 * friendSuggestions - 2d array which stores the names of the suggested friends
 * numFriendsOfSuggestions - stores the friend count of the suggested friends
 */
void sortRecommendations(int suggestions, char friendsSuggestions[][80], int numFriendsOfSuggestions[]) {
    //selection sort
    int maxIndex;
    int swap;
    char nameSwap[80];
    //sort by friend count using selection sort
    for (int i = 0; i < suggestions - 1; i++) {
        maxIndex = i;
        for (int j = i + 1; j < suggestions; j++) {
            if (numFriendsOfSuggestions[j] > numFriendsOfSuggestions[maxIndex]) {
                maxIndex = j;
            }
        }
        swap = numFriendsOfSuggestions[i];
        strcpy(nameSwap, friendsSuggestions[i]);
        numFriendsOfSuggestions[i] = numFriendsOfSuggestions[maxIndex];
        strcpy(friendsSuggestions[i], friendsSuggestions[maxIndex]);
        numFriendsOfSuggestions[maxIndex] = swap;
        strcpy(friendsSuggestions[maxIndex], nameSwap);
    }
    //sort by alphabetical order if friend count is the same using insertion sort
    for (int i = 1; i < suggestions; i++) {
        int j = i;
        while (j > 0 && (numFriendsOfSuggestions[j] == numFriendsOfSuggestions[j - 1]) && (strcmp(friendsSuggestions[j], friendsSuggestions[j - 1]) < 0)) {
            swap = numFriendsOfSuggestions[j];
            strcpy(nameSwap, friendsSuggestions[j]);
            numFriendsOfSuggestions[j] = numFriendsOfSuggestions[j - 1];
            strcpy(friendsSuggestions[j], friendsSuggestions[j - 1]);
            numFriendsOfSuggestions[j - 1] = swap;
            strcpy(friendsSuggestions[j - 1], nameSwap);
            j--;
        }
    }
}

/* This prints the names of the top recommended users (at most 2)
 *
 * Input:
 * name - The name of the selected user
 * suggestions - The total number of suggestions available
 * friendsSuggestions - 2d array which stores the names of the suggested friends
 */
void getSuggestion(char name[80], int suggestions, char friendsSuggestions[][80]) {
    printf("Suggested Friends for %s:\n", name);
    if (suggestions == 1) {
        printf("%s\n", friendsSuggestions[0]);
    } else if (suggestions > 1) {
        printf("%s\n", friendsSuggestions[0]);
        printf("%s\n", friendsSuggestions[1]);
    } else {
        printf("No Suggestions.\n");
    }

}
