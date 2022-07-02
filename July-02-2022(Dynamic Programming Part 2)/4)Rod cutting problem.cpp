#include<bits/stdc++.h>

int t[101][101];
int solve(int i, int length, vector<int>& arr)
{
    if(i == 0)
    {
        return length * arr[0];
    }
    if(length < 0) return INT_MIN;
    
    if(t[i][length] != -1)
        return t[i][length];
    
    int Take = INT_MIN;
    int notTake = solve(i - 1, length, arr);
    
    if(i + 1 <= length)
    Take = arr[i] + solve(i, length - (i + 1), arr);
    
    return t[i][length] = max(notTake, Take);
}
int cutRod(vector<int> &arr, int n)
{
    // Write your code here.
    memset(t, -1, sizeof(t));
    return solve(n - 1, n, arr);
}

