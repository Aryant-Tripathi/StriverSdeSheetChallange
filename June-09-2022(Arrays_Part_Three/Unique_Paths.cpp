#include <bits/stdc++.h> 

int t[16][16];
int solve(int i, int j, int row, int col)
{
    if(i >= row || j >= col)
        return 0;
    
    if(i == row - 1 && j == col - 1)
    {
        return 1;
    }
    
    if(t[i][j] != -1)
        return t[i][j];
    
    int ans1 = solve(i + 1, j, row, col);
    int ans2 = solve(i, j + 1, row, col);
    
    return t[i][j] =  ans1 + ans2;
}
int uniquePaths(int row, int col) {
    // Write your code here.
    
    memset(t, -1, sizeof(t));
    
    return solve(0, 0, row, col);
}