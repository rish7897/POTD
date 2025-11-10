#include<iostream>
#include<vector>
using namespace std;

// dp memoisation
int maxProfit(int buy, int i, vector < vector < int >> & dp, vector < int > & arr) {
    int n = arr.size();
    if (i >= n) {
        return 0;
    }
    if (dp[i][buy] != -1) {
        return dp[i][buy];
    }
    if (buy) {
        int take = -arr[i] + maxProfit(0, i + 1, dp, arr);
        int skip = maxProfit(1, i + 1, dp, arr);
        dp[i][buy] = max(take, skip);
        return max(take, skip);
    } else {
        int sell = arr[i] + maxProfit(1, i + 2, dp, arr);
        int skip = maxProfit(0, i + 1, dp, arr);
        dp[i][buy] = max(sell, skip);
        return max(sell, skip);
    }
    return 0;
}
int maxProfit(vector < int > & arr) {
    int n = arr.size();
    vector < vector < int >> dp(n, vector < int > (2, -1));
    return maxProfit(1, 0, dp, arr);
}