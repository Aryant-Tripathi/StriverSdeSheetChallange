#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int target) {
    // Write your code here.
    
    sort(arr.begin(), arr.end());
    set<vector<int>> s;
    vector<vector<int>> ans;
    
    for(int i = 0; i < n - 1; i++)
    {
        int low = i + 1, high = n - 1;
        
        while(low <= high)
        {
            int sum = arr[i] + arr[low] + arr[high];
            if(sum == target)
            {
                if(i != low && i != high && low != high)
                {
                    vector<int> temp = 
                        {arr[i], arr[low], arr[high]};
                    if(s.find(temp) == s.end())
                    {
                        ans.push_back(temp);
                        s.insert(temp);
                   }
                }
                
                low++;
                high--;
                
            }
            else if(sum < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    
    //if(ans.empty()) ans.push_back({-1});
    return ans;
}