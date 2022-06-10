#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    
    // a ^ b = c
    // b ^ a = c
    // c ^ a = b
    // c ^ b = a
    
    // see here
    // a ^ b = c 
    // c ^ b = a
    int n = arr.size();
    map<int, int> mp;
    
    int currXOR = 0;
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        currXOR = currXOR ^ arr[i];
        
        if(currXOR == k)
            ans++;
        
        int alsoFind = currXOR ^ k;
        if(mp.find(alsoFind) != mp.end())
        {
            ans += mp[alsoFind];
        }
         mp[currXOR]++;
    }
    
    return ans;
}