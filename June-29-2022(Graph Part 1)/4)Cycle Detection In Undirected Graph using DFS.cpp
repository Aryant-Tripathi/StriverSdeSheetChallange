vector<int> adj[5001];
bool dfs(int node, int parent, vector<int> &vis)
{
    vis[node] = true;
    
    for(int near: adj[node])
    {
        if(!vis[near])
        {
            if(dfs(near, node, vis))
            {
                return true;
            }
        }
        else if(near != parent)
        {
            return true;
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
    
    vector<int> vis(n + 1, false);
    for(int i = 0; i < n; i++)
    {
        if(!vis[i] && dfs(i, -1, vis))
            return "Yes";
    }
    
    return "No";
}

