#include<bits/stdc++.h>

int t[101][101];
int solve(int i, int j, vector<vector<int>> &arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
        return INT_MAX;
    
    if(i == arr.size() - 1 && j == arr[0].size() - 1)
        return arr[i][j];
    
    if(t[i][j] != -1)
        return t[i][j];
    
    return t[i][j] = arr[i][j] + min(solve(i + 1, j, arr), 
                          solve(i, j + 1, arr));
}
int minSumPath(vector<vector<int>> &arr) {
    // Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    memset(t, -1, sizeof(t));
    return solve(0, 0, arr);
}