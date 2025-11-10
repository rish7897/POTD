#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& arr) {
    // code here
    int n = arr.size();
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return max(arr[1] - arr[0], 0);
    }
    
    // 0th index sell 1st buy
    vector<vector<int>> dp(n, vector<int>(2, -1));
    dp[0] = {0, -arr[0]};
    dp[1] = {max(arr[1] + dp[0][1], dp[0][0]), max(-arr[1], dp[0][1])};
    for(int i = 2; i < n; i++){
        dp[i][0] = max(arr[i] + dp[i-1][1], dp[i-1][0]);
        dp[i][1] = max(-arr[i] + dp[i-2][0], dp[i-1][1]);
    }
    return max(dp[n-1][0], dp[n-1][1]);
}