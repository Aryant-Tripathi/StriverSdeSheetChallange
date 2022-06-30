#include<bits/stdc++.h>

int par[10001];

int find(int a)
{
    if(par[a] < 0) return a;
    
    return par[a] = find(par[a]);
}

void Union(int a, int b)
{
    par[a] = b;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    // Write your code here.
    vector<pair<int, pair<int, int>>> adj;
    for(int i = 1; i <= n; i++) par[i] = -1;
    
    for(int i = 0; i < m; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        
        adj.push_back({w, {u, v}});
    }
    
    sort(adj.begin(), adj.end());
    
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        int a = adj[i].second.first;
        int b = adj[i].second.second;
        
        int para = find(a);
        int parb = find(b);
        
        if(para != parb)
        {
            sum += adj[i].first;
            Union(para, parb);
        }
    }
    
    return sum;
}