#include<iostream>
#include<vector>
using namespace std;

// dp memoisation time O(n*n*n*n) space O(n*n*n*n)
int chocolatePickup(
    int row1, int col1, int row2, int col2, 
    vector<vector<int>> &mat, 
    vector<vector<vector<vector<int>>>>& dp
) {
    int n = mat.size();
    if(row1  == n || col1 == n || row2 == n || col2 == n){
        return -1;
    }
    if(dp[row1][col1][row2][col2] != -2){
        return dp[row1][col1][row2][col2];
    }
    if(mat[row1][col1] == -1 || mat[row2][col2] == -1){
        return -1;
    }
    if(row1 == n-1 && col1 == n-1 && row2 == n-1 && col2 == n-1){
        return mat[row1][col1];
    }
    int ans1 = chocolatePickup(row1 + 1, col1, row2 + 1, col2, mat, dp);
    int ans2 = chocolatePickup(row1 + 1, col1, row2, col2 + 1, mat, dp);
    int ans3 = chocolatePickup(row1, col1 + 1, row2 + 1, col2, mat, dp);
    int ans4 = chocolatePickup(row1, col1 + 1, row2, col2 + 1, mat, dp);
    int ans = max(max(ans1, ans2), max(ans3, ans4));
    if(ans == -1){
        dp[row1][col1][row2][col2] = -1;
        return -1;
    }
    ans = ans + mat[row1][col1];
    if(row1 != row2 && col1 != col2){
        ans += mat[row2][col2];
    }
    dp[row1][col1][row2][col2] = ans;
    return ans;
}
int chocolatePickup(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<vector<vector<int>>>>dp(
        n, vector<vector<vector<int>>>(
            n, vector<vector<int>>(
                n, vector<int>(
                    n, -2))));
    return max(chocolatePickup(0, 0, 0, 0, mat, dp), 0);
}