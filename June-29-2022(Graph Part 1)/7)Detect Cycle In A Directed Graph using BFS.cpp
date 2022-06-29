// IDEA:
// Using bfs we try to generate topological sort
// if topological sort possible that means ki graph is
// Directed Acyclic Graph (means having no cycle)
// if topological sort not possible that means cycle is present
/**************************************************************/

#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n + 1];
    int indegree[n + 1] = {0};
    
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    vector<bool> vis(n + 1, false);
    
    queue<int> q;
    int count = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        count++;
        
        for(int near: adj[curr])
        {
            indegree[near]--;
            if(indegree[near] == 0)
                q.push(near);
        }
    }
    
    return (count != n);

}