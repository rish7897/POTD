#include<iostream>
using namespace std;

int maxProfit(int index, vector<vector<int>> &jobs){
    if(index == jobs.size()){
        return 0;
    }
    int profit = maxProfit(index + 1, jobs);
    int start = index + 1;
    int end = jobs.size() - 1;
    int next = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(jobs[mid][0] >= jobs[index][1]){
            next = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    if(next == -1){
        jobs[index][2] = max(profit, jobs[index][2]);
    }else{
        jobs[index][2] = max(profit, jobs[index][2] + jobs[next][2]);
    }
    return jobs[index][2];
}
int maxProfit(vector<vector<int>> &jobs) {
    // code here
    sort(jobs.begin(), jobs.end());
    return maxProfit(0, jobs);
}