#include<iostream>
#include<string>
#include<vector>
using namespace std;

// dp memoisation
int findMaxForm(vector < string > & strs, int m, int n, int i, vector < vector < vector < int >>> & dp) {
    if (m < 0 || n < 0) {
        return -1;
    }
    if (i >= strs.size()) {
        return 0;
    }
    if (dp[i][m][n] != -2) {
        return dp[i][m][n];
    }
    int count0 = 0;
    int count1 = 0;
    for (int j = 0; j < strs[i].size(); j++) {
        if (strs[i][j] == '0') {
            count0++;
        } else {
            count1++;
        }
    }
    dp[i][m][n] = findMaxForm(strs, m, n, i + 1, dp);
    int ans2 = findMaxForm(strs, m - count0, n - count1, i + 1, dp);
    if (ans2 != -1) {
        dp[i][m][n] = max(dp[i][m][n], 1 + ans2);
    }
    return dp[i][m][n];
}
int findMaxForm(vector < string > & strs, int m, int n) {
    vector < vector < vector < int >>> dp(strs.size() + 1, vector < vector < int >> (m + 1, vector < int > (n + 1, -2)));
    return findMaxForm(strs, m, n, 0, dp);
}