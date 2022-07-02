#include<bits/stdc++.h>

int t[1001][1001];
bool solve(int i, int sum, int k, vector<int>& arr)
{
     if(sum == k)
        return true;
    
    if(i >= arr.size())
        return false;
    
    if(sum > k) return false;
    
    if(t[i][sum] != -1)
        return t[i][sum];
    
    bool take = solve(i + 1, sum + arr[i], k, arr);
    
    bool notTake = solve(i + 1, sum, k, arr);
    
    return t[i][sum] = (take || notTake);
    
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    memset(t, -1, sizeof(t));
    
    return solve(0, 0, k, arr);
}