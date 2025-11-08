#include<iostream>
using namespace std;

// dp memoisation
int numberOfPath(int row, int col, vector<vector<int>>& mat, int k, vector<vector<vector<int>>>& paths){
    int n = mat.size();
    int m = mat[0].size();
    if(row == n || col == m){
        return 0;
    }
    if(paths[row][col][k] != -1){
        return paths[row][col][k];
    }
    int ans;
    if(row == n - 1 && col == m - 1){
        ans = (k == mat[row][col]);
    }else if(k < mat[row][col]){
        ans = 0;
    }else{
        int rightPaths = numberOfPath(row, col + 1, mat, k - mat[row][col], paths);
        int downPaths = numberOfPath(row + 1, col, mat, k - mat[row][col], paths);
        ans = rightPaths + downPaths;
    }
    paths[row][col][k] = ans;
    return ans;
}
int numberOfPath(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<int>>> paths(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    return numberOfPath(0, 0, mat, k, paths);
}