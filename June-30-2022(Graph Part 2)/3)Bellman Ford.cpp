int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        for(auto e: edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
           int distance = dist[u] == INT_MAX ? INT_MAX : w + dist[u];
            
            dist[v] = min(dist[v], distance);
        }
    }
    
    if(dist[dest]==INT_MAX)
        return 1000000000;
        
    return dist[dest];
}