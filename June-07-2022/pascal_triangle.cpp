#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> t(n);
    
    for(int i = 0; i < n; i++)
    {
        t[i].resize(i + 1);
        t[i][0] = t[i][i] = 1;
        
        for(int j = 1; j < i; j++)
        {
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
    }
    
    return t;
}

