#include<iostream>
using namespace std;

// dp tabulation space optimised
int numberOfPath(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> prev(m, vector<int>(k + 1, 0));
    vector<vector<int>> curr(m, vector<int>(k + 1, 0));
    if(mat[0][0] <= k){
        curr[0][mat[0][0]] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int sum = 0; sum <= k; sum++){
                if(i != 0 || j != 0){
                    curr[j][sum] = 0;
                }
                if(sum - mat[i][j] >= 0){
                    if(i > 0){
                        curr[j][sum] += prev[j][sum - mat[i][j]];
                    }
                    if(j > 0){
                        curr[j][sum] += curr[j - 1][sum - mat[i][j]];   
                    }
                }
            }
        }
        prev = curr;
    }
    return curr[m -1][k];
}