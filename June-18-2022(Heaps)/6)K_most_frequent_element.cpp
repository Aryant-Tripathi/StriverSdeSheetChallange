#include<bits/stdc++.h>
#define pii pair<int, int>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for(int i: arr) mp[i]++;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(auto x: mp)
    {
        pq.push({x.second, x.first});
        
        if(pq.size() > k) pq.pop();
    }
    
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}