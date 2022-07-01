#include<bits/stdc++.h>
int t[1001][1001];

int solve(int i, int mxWeight, vector<int> &values, vector<int> &weights)
{
    if(i >= values.size())
        return 0;
    
    if(t[i][mxWeight] != -1)
        return t[i][mxWeight];
    
    if(mxWeight <= 0) return 0;
    
    int notTake = solve(i + 1, mxWeight, values, weights);
    
    int Take = -2167982;
    if(mxWeight >= weights[i])
    Take = values[i] + solve(i + 1, mxWeight - weights[i], 
                                 values, weights);
    
    return t[i][mxWeight] = max(notTake, Take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    memset(t, -1, sizeof(t));
    return solve(0, w, values, weights);
}