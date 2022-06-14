#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++)
    {
        arr.push_back({start[i], end[i]});
    }
    
    sort(arr.begin(), arr.end());
    
    int ans = 1, prev = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].first >= arr[prev].second)
        {
            ans++;
            prev = i;
        }
        else
        {
            if(arr[i].second < arr[prev].second)
            {
                prev = i;
            }
        }
    }
    
    return ans;
}