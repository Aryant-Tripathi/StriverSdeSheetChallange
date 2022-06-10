#include <bits/stdc++.h> 
int parent[100001], Rank[100001];
    
    int find(int a)
    {
        if(parent[a] == a)
            return a;
        
        return parent[a] = find(parent[a]);
    }
    
    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if(a == b)
            return;
        
        if(Rank[a] > Rank[b])
        {
            // a would be parent
            parent[b] = a;
            Rank[a] += Rank[b];
        }
        else
        {
            // b would be parent
            parent[a] = b;
            Rank[b] += Rank[a];
        }
    }
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    // int n = arr.size();
        if(n == 0) return 0;
        
        for(int i = 0; i < n; i++) parent[i] = i, Rank[i] = 1;
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(arr[i]) != mp.end()) continue;
            
            if(mp.find(arr[i] - 1) != mp.end())
            {
                Union(mp[arr[i] - 1], i);
            }
            
            if(mp.find(arr[i] + 1) != mp.end())
            {
                Union(mp[arr[i] + 1], i);
            }
            
             mp[arr[i]] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, Rank[i]);
        }
        
        return ans;
}