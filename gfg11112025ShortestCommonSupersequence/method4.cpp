#include<iostream>
using namespace std;

// using super sequence method
// dp tabulation space optimisation
int minSuperSeq(string &s1, string &s2) {
    int n1  = s1.size();
    int n2 = s2.size();
    vector<int> prev(n2 + 1);
    for(int i1 = 0; i1 <= n1; i1++){
        vector<int> curr(n2 + 1);
        for(int i2 = 0; i2 <= n2; i2++){
            if(i1 == 0 && i2 == 0){
                curr[0] = 0;
            }else if(i1 == 0){
                curr[i2] = i2;
            }else if(i2 == 0){
                curr[i2] = i1;
            }else if(s1[i1 - 1] == s2[i2 - 1]){
                curr[i2] = prev[i2-1] + 1;
            }else{
                curr[i2] = 1 + min(curr[i2-1], prev[i2]);
            }
        }
        prev = curr;
    } 
    return prev[n2];
}