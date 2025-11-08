#include<iostream>
using namespace std;

// dp tabulation
int numberOfPath(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<int>>> paths(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
    if(mat[0][0] <= k){
        paths[0][0][mat[0][0]] = 1;    
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int sum = 0; sum <= k; sum++){
                if(sum - mat[i][j] >= 0){
                    if(i > 0){
                        paths[i][j][sum] += paths[i - 1][j][sum - mat[i][j]];
                    }
                    if(j > 0){
                        paths[i][j][sum] += paths[i][j - 1][sum - mat[i][j]];
                    }   
                }
            }
        }
    }
    return paths[n -1][m - 1][k];
}