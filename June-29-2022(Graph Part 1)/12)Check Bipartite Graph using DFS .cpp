 /* IDEA: 
    1) Bipartite Graph ka mtlb hai ki adjcant nodes ka colour same nhi hona
    chaiye.
    2) hm ek colour array bnayenge jisko intially '-1' se intiliaze kr denge,
    mtlb yeh ki abhi isko koi colour nhi diya gya hai.
    3) Since Graph main multiple components main bhi ho skte hain toh hm hr node
    ko visit krke dekhenge.
    4) hr time uss node ko hm root node bna ke bhejenge aur uss time isko colour
    zero de denge, ab iske adjcant main travel krenge, agr iske adjcant main 
    iske nodes ka colour -1 hai toh uss curr node ke opposite ka colur de denge.
    5) last main hm bs dekh lenge ki kya kisi node ka uske adjcant node ke 
    saath colour same hai yaa nhi, agr haan toh false return kr do, nhi toh true.
    */

#include<bits/stdc++.h>
bool dfs(vector<int> adj[],vector<int>& color,int i)
{
    if(color[i]==-1)
    {
        color[i] = i;
    }
    
    for(auto x : adj[i])
    {
        if(color[x]==-1)
        {
            color[x] = 1- color[i];
            if(!dfs(adj,color,x))
            {
                return false;
            }
        }
        else if(color[x]==color[i])
        {
            return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int n = edges[0].size();
    vector<int> adj[n + 1];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
     vector<int> color(n + 1, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(adj, color, i))
                {
                    return false;
                }
            }
            
        }
    
       return true;
}