// if (low link value == in time) , all the nodes present in 
// onstack array are the part of SCC

#include<bits/stdc++.h>

vector<int> adj[2001];
bool vis[2001], onstack[2001];
int in[2001], low[2001];
stack<int> s;
int timer;
vector<vector<int>> ans;

void dfs(int node)
{
    vis[node] = true;
    onstack[node] = true;
    
    in[node] = low[node] = timer++;
    s.push(node);
    
    for(int near: adj[node])
    {
        if(vis[near] && onstack[near])
        {
            low[node] = min(low[node], in[near]);
        }
        else
        {
            if(vis[near] == false)
            {
                dfs(near);
                if(onstack[near])
                {
                    low[node] = min(low[node], low[near]);
                }
            }
        }
    }
    
    if(in[node] == low[node])
    {
        int u;
        vector<int> temp;
        while(true)
        {
            int u = s.top();
            temp.push_back(s.top());
            s.pop();
            
            onstack[u] = false;
            
            if(u == node)
                break;
        }
        ans.push_back(temp);
    }
        
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    ans.clear();
    
    for(int i = 0; i <= n; i++)
    {
        adj[i].clear();
        in[i] = 0, low[i] = 0;
        vis[i] = false, onstack[i] = false;
        timer = 1;
    }
    
   while(!s.empty()) s.pop();
    
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    
    return ans;
    
}