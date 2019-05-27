/*
 * This function populate the selected user with possible friendsSuggestions, it fills
 * friendsSuggestions with the suggested names and also fills numFriendsOfSuggestions with
 * the friend count of each suggested friend.
 *
 * Input:
 * totalUsers - total number of users (max 6)
 * user - is the index of the current selected user
 * friendList - contains the friends of the selected user
 * numbernumFriendsPerUser - friend count of each user
 * friendSuggestions - stores the names of the suggested friends
 * numFriendsOfSuggestions - stores the friend count of the suggested friends
 *
 * Output:
 * count - the total number of suggested friends
 */
int populateArrays(int totalUsers, int user, char friendList[][80], char users[][80], int numbernumFriendsPerUser[6], char friendsSuggestions[5][80], int numFriendsOfSuggestions[5]);

/* This function sorts users depending on the number of their friends (from the biggest to the smaller).
 * If 2 users have the same number of friends they will be sorted alphabetically.
 * When sorting according to the number of their friends, selection sort is used
 * for efficiency purposes.
 * When sorting alphabetically, insertion sort is used as the array is already partially
 * sorted (faster)
 *
 * Input:
 * suggestions - Number of recommended users
 * friendSuggestions - 2d array which stores the names of the suggested friends
 * numFriendsOfSuggestions - stores the friend count of the suggested friends
 */
void sortRecommendations(int suggestions, char friendsSuggestions[][80], int numFriendsOfSuggestions[]);

/* This prints the names of the top recommended users (at most 2)
 *
 * Input:
 * name - The name of the selected user
 * suggestions - The total number of suggestions available
 * friendsSuggestions - 2d array which stores the names of the suggested friends
 */
void getSuggestion(char name[80], int suggestions, char friendsSuggestions[][80]);
