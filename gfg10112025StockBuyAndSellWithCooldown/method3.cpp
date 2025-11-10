#include<iostream>
#include<vector>
using namespace std;

// dp tabular space optimised 
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return max(arr[1] - arr[0], 0);
    }
    
    // 0th index sell 1st buy
    int prevprevSell = 0;
    int prevBuy = max(-arr[1], -arr[0]);
    int prevSell = max(arr[1] - arr[0], 0);
    
    for(int i = 2; i < n; i++){
        int currSell = max(prevSell, arr[i] + prevBuy);
        int currBuy = max(prevBuy, -arr[i] + prevprevSell);
        prevprevSell = prevSell;
        prevSell = currSell;
        prevBuy = currBuy;
    }
    return max(prevBuy, prevSell);;
}