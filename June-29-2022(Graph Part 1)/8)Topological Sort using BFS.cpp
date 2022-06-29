#include<bits/stdc++.h>

vector<int> adj[10001];
int inorder[10001];
vector<int> ans;

void kahn(int v)
{
    queue<int> q;
    
    for(int i = 0; i < v; i++)
    {
        if(inorder[i] == 0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        ans.push_back(curr);
        for(int near: adj[curr])
        {
            inorder[near]--;
            if(inorder[near] == 0) q.push(near);
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    for(int i = 0; i < v; i++)
        adj[i].clear(), inorder[i] = 0;
    
    ans.clear();
    
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        inorder[v]++;
    }
    
    kahn(v);
    
    return ans;
    
}