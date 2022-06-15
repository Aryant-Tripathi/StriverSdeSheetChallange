#include<bits/stdc++.h>

vector<vector<int>> ans;
map<vector<int>, int> mp;
void solve(int i, vector<int>& temp, vector<int>& arr)
{
    if(i >= arr.size())
    {
        if(mp.find(temp) != mp.end())
            return;
        
        ans.push_back(temp);
        mp[temp]++;
        return;
    }
    
    solve(i + 1, temp, arr);
    
    temp.push_back(arr[i]);
    solve(i + 1, temp, arr);
    temp.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    ans.clear();
    mp.clear();
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(0, temp, arr);
    
    sort(ans.begin(), ans.end());
    return ans;
}