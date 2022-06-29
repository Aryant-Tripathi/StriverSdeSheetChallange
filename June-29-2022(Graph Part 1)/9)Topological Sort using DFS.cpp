#include<bits/stdc++.h>

void dfs_toposort(int node, vector<int> adj[],
                 vector<bool>& vis, stack<int>& s)
{
    vis[node] = true;
    
    for(int near: adj[node])
    {
        if(!vis[near])
        {
            dfs_toposort(near, adj, vis, s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v + 1];
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    stack<int> s;
    vector<bool> vis(v, false);
    
    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs_toposort(i, adj, vis, s);
        }
    }
    
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}