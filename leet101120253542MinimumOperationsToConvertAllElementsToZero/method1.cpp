#include<iostream>
using namespace std;

int minOperations(vector<int>& nums) {
    // monotonic stack
    stack<int> s;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        while(!s.empty() && nums[i] < s.top()){
            s.pop();
        }
        
        if(nums[i] != 0 && (s.empty() || nums[i] > s.top()) ){
            s.push(nums[i]);
            count++;
        }
    }
    return count;
}