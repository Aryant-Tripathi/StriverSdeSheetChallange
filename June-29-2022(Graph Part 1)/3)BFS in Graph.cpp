#include<bits/stdc++.h>
vector<int> adj[10001];

void bfs(int node, vector<bool> &vis, vector<int>& ans)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    
    sort(adj[node].begin(),adj[node].end());    
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        
        for(int near: adj[curr])
        {
            if(!vis[near])
            {
                q.push(near);
                vis[near] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    for(int i = 0; i < vertex; i++)
        adj[i].clear();
    
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(vertex, false);
    vector<int> ans;
    
    for(int i = 0; i < vertex; i++)
    {
        if(!vis[i])
        {
            bfs(i, vis, ans);
        }
    }
    
    return ans;
}