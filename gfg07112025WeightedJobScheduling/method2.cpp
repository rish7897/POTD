#include<iostream>
using namespace std;

int maxProfit(vector<vector<int>> &jobs) {
    // dp tabulation
    sort(jobs.begin(), jobs.end());
    for(int i = jobs.size() - 2; i >= 0; i--){
        int start = i + 1;
        int end = jobs.size() - 1;
        int nextjob = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(jobs[mid][0] >= jobs[i][1]){
                end = mid - 1;
                nextjob = mid;
            }else{
                start = mid + 1;
            }
        }
        if(nextjob == -1){
            jobs[i][2] = max(jobs[i + 1][2], jobs[i][2]);
        }else{
            jobs[i][2] = max(jobs[i + 1][2], jobs[i][2] + jobs[nextjob][2]);
        }
        
    }
    return jobs[0][2];
}