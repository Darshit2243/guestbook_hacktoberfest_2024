#include <iostream>
#include <vector>
using namespace std;

// Function to check if a subset with the given sum exists
bool isSubsetSum(const vector<int>& set, int n, int sum) {
    // Create a 2D array to store the solutions of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then a subset with sum 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // If sum is not 0 and set is empty, then there is no subset with non-zero sum
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }

    // Fill the subset table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                // Include the current element or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                // Exclude the current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return whether the subset with the given sum is possible
    return dp[n][sum];
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = set.size();

    if (isSubsetSum(set, n, sum)) {
        cout << "Found a subset with given sum" << endl;
    } else {
        cout << "No subset with given sum" << endl;
    }

    return 0;
}
