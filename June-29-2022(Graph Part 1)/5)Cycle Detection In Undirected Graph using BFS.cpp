#include<bits/stdc++.h>

vector<int> adj[5001];
bool bfs(int node, vector<bool>& vis)
{
    queue<pair<int, int>> q; // node, prev
    q.push({node, -1});
    vis[node] = true;
    
    while(!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();
        
        for(int near: adj[curr])
        {
            if(!vis[near])
            {
                vis[near] = true;
                q.push({near, curr});
            }
            else if(near != prev)
            {
                return true;
            }
        }
    }
    
    return false;
    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    for(int i = 0; i <= n; i++)
        adj[i].clear();
    
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(n + 1, false);
    for(int i = 0; i <= n; i++)
    {
        if(!vis[i])
        {
            if(bfs(i, vis))
            {
                return "Yes";
            }
        }
    }
    
    return "No";
}

