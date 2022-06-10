#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector<int> arr) {
  // Write your code here
    int n = arr.size();
    
    unordered_map<int, int> mp;
    int curr_sum = 0;
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        
        if(curr_sum == 0)
        {
            ans = i + 1;
        }
        else if(mp.find(curr_sum) != mp.end())
        {
            ans = max(ans, i - mp[curr_sum]);
        }
        else
        {
            mp[curr_sum] = i;
        }
    }
    
    return ans;
}