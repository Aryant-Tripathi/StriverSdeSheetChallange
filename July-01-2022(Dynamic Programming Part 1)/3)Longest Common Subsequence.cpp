#include<bits/stdc++.h>

int t[1001][1001];
int solve(string first, string second, int n1, int n2)
{
    if(n1 == 0 || n2 == 0) return 0;
    
    if(t[n1][n2] != -1) return t[n1][n2];
    
    if(first[n1 - 1] == second[n2 - 1])
    {
        return t[n1][n2] = 1 + solve(first, second, n1 - 1, n2 - 1);
    }
    
    return t[n1][n2] = max(solve(first, second, n1 - 1, n2),
                          solve(first, second, n1, n2 - 1));
}
int lcs(string first, string second)
{
	//Write your code here
    memset(t, -1, sizeof(t));
    
    return solve(first, second, first.size(), second.size());
}