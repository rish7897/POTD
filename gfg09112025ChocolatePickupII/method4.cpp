#include<iostream>
#include<vector>
using namespace std;

// dp memoisation time O(n*n*n) space O(n*n*n) 
int chocolatePickup(int row1, int col1, int row2, 
vector<vector<int>> &mat, 
vector<vector<vector<int>>>& dp){
    int n = mat.size();
    if(row1 == n || col1 == n || row2 == n){
        return -1;
    }
    if(dp[row1][col1][row2] != -2){
        return dp[row1][col1][row2];
    }
    if(row1 == n-1 && col1 == n-1 && row2 == n-1){
        dp[row1][col1][row2] = mat[n-1][n-1];
        return mat[n-1][n-1];
    }
    if(mat[row1][col1] == -1 || mat[row2][row1 + col1 - row2] == -1){
        dp[row1][col1][row2] = -1;
        return -1;
    }
    int ans = -1;
    ans = max(ans, chocolatePickup(row1 + 1, col1, row2, mat, dp));
    ans = max(ans, chocolatePickup(row1 + 1, col1, row2 + 1, mat, dp));
    ans = max(ans, chocolatePickup(row1, col1 + 1, row2, mat, dp));
    ans = max(ans, chocolatePickup(row1, col1 + 1, row2 + 1, mat, dp));
    if(ans == -1 || mat[row1][col1] == -1 || mat[row2][row1+col1-row2] == -1){
        dp[row1][col1][row2] = -1;
        return -1;
    }else{
        ans += mat[row1][col1];
        if(row1 != row2){
            ans += mat[row2][row1+col1-row2];
        }
    }
    dp[row1][col1][row2] = ans;
    return ans;
}
int chocolatePickup(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(
            n, vector<int>(
                n, -2)));
                
    return max(chocolatePickup(0, 0, 0, mat, dp), 0);
}