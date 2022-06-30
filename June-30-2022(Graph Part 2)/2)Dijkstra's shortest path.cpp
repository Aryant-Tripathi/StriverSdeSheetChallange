#include<bits/stdc++.h>
#define pii pair<int, int>

vector<pii> adj[1001];
vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int numedges, int source) {
    // Write your code here.
   
    for(int i = 0; i < vertices; i++)
        adj[i].clear();
    
    for(int i = 0; i < numedges; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];
        
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<int> dist(vertices, INT_MAX);
    pq.push({0, source});
    dist[source] = 0;
    
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        
        for(pii edge: adj[curr])
        {
            if(curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
    
    return dist;
}

