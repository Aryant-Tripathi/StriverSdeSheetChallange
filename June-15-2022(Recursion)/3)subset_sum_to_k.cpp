



// TLE APPROACH
/*#include<bits/stdc++.h>

vector<vector<int>> ans;
map<vector<int>, int> mp;

void solve(int i, int sum, int target, vector<int>& temp, vector<int>& arr)
{
    if(i >= arr.size())
    {
        if(mp.find(temp) != mp.end())
            return;
        else
        {
            if(sum == target)
            {
                ans.push_back(temp);
                mp[temp]++;
            }
        }
        
        return;
    }
    
    solve(i + 1, sum, target, temp, arr);
    
    int orig = sum;
    temp.push_back(arr[i]);
    solve(i + 1, sum + arr[i], target, temp, arr);
    temp.pop_back();
    sum = orig;
    
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    ans.clear();
    mp.clear();
    
   sort(arr.begin(), arr.end());
    
    vector<int> temp;
    
    solve(0, 0, target, temp, arr);
    sort(ans.begin(), ans.end());
    return ans;
} */

