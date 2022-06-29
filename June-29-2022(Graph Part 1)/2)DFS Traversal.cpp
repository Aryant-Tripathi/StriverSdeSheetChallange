#include<bits/stdc++.h>
vector<int> adj[1001];

void dfs(int node, vector<bool>& vis, vector<int>& temp)
{
    vis[node] = true;
    temp.push_back(node);
    
    for(int near: adj[node])
    {
        if(!vis[near])
        {
            dfs(near, vis, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    for(int i = 0; i < V; i++)
        adj[i].clear();
    
    for(int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(V, false);
    vector<vector<int>> ans;
    
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            vector<int> temp;
            dfs(i, vis, temp);
            //sort(temp.begin(), temp.end());   
            ans.push_back(temp);
        }
    }
    
    return ans;
}