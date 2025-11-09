#include<iostream>
#include<vector>
using namespace std;

// dp tabular time O(n*n*n) space O(n*n*n)
int chocolatePickup(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(
            n, vector<int>(
                n)));
    
    for(int row1 = 0; row1 < n; row1++){
        for(int col1 = 0; col1 < n; col1++){
            for(int row2 = 0; row2 < n; row2++){
                if(row1 == 0 && col1 == 0 && row2 == 0){
                    dp[0][0][0] = mat[0][0];
                }else{
                    int ans = -1;
                    if(row1 >= 1 && row2 >= 1){
                        ans = max(ans, dp[row1-1][col1][row2-1]);
                    }
                    if(col1 >= 1 && row2 >= 1){
                        ans = max(ans, dp[row1][col1-1][row2-1]);
                    }
                    if(row1 >= 1 && row1 +col1 - row2 >= 1){
                        ans = max(ans, dp[row1-1][col1][row2]);
                    }
                    if(col1 >= 1 && row1 + col1 - row2 >= 1){
                        ans = max(ans, dp[row1][col1-1][row2]);
                    }
                    if(ans == -1 || mat[row1][col1] == -1 || mat[row2][row1+col1-row2] == -1){
                        dp[row1][col1][row2] = -1;
                    }else{
                        ans += mat[row1][col1];
                        if(row1 != row2){
                            ans += mat[row2][row1+col1-row2];
                        }
                        dp[row1][col1][row2] = ans;
                    }
                }
            }
        }
    }
    return max(dp[n-1][n-1][n-1], 0);
}