#include<bits/stdc++.h>

int t[101][101];
int solve(int i, int j, vector<int>& arr)
{
    if(i >= j) return 0;
    
    if(t[i][j] != -1) return t[i][j];
    
    int mn = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int temp = solve(i, k, arr) + 
                   solve(k + 1, j, arr) +
                   arr[i - 1] * arr[k] * arr[j];
        
        if(temp < mn) mn = temp;
    }
    
    return t[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    memset(t, -1, sizeof(t));
    return solve(1, n - 1, arr);
}