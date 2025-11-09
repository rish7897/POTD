#include<iostream>
#include<vector>
using namespace std;

// dp tabular time O(n*n*n*n) space O(n*n*n*n)
int chocolatePickup(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<vector<vector<int>>>>dp(
        n, vector<vector<vector<int>>>(
            n, vector<vector<int>>(
                n, vector<int>(
                    n, -2))));
                    
    
    for(int row1 = 0; row1 < n; row1++){
        for(int col1 = 0; col1 < n; col1++){
            for(int row2 = 0; row2 < n; row2++){
                for(int col2 = 0; col2 < n; col2++){
                    if(row1 == 0 && col1 == 0 && row2 == 0 && col2 == 0){
                        dp[0][0][0][0] = mat[0][0];
                    }
                    else{
                        int ans = -1;
                        if(row1-1 >= 0 && row2-1 >= 0){
                            ans = max(ans, dp[row1-1][col1][row2-1][col2]);   
                        }
                        if(row1-1 >= 0 && col2-1 >= 0){
                            ans = max(ans, dp[row1-1][col1][row2][col2-1]);
                        }
                        if(col1-1 >= 0 && row2-1 >= 0){
                            ans = max(ans, dp[row1][col1-1][row2-1][col2]);    
                        }
                        if(col1-1 >= 0 && col2-1 >= 0){
                            ans = max(ans, dp[row1][col1-1][row2][col2-1]);    
                        }
                    
                        if(ans == -1 || mat[row1][col1] == -1 || mat[row2][col2] == -1){
                            dp[row1][col1][row2][col2] = -1;
                        }else{
                            ans += mat[row1][col1];
                            if(row1 != row2 && col1 != col2){
                                ans += mat[row2][col2];
                            }
                            dp[row1][col1][row2][col2] = ans;
                        }
                    }
                    
                }
            }
        }
    }
    return max(dp[n-1][n-1][n-1][n-1], 0);
}