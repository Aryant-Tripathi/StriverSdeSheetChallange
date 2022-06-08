#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    
    ans.push_back(arr[0]);
    int j = 0;
    for(int i = 1; i < n; i++)
    {
        int currLast = ans[j][1];
        
        if(currLast >= arr[i][0])
        {
            ans[j][1] = max(ans[j][1], arr[i][1]);
               // why max?
               // suppose interval kch aisa hota,
                // [1,6], [2,5]
                // so, 6 >= 2, means merge krna hai
                // toh merge hokr kya bnenge, [1,6] 
                // therefore we check between 6 and 5 which is max
        }
        else 
        {
            ans.push_back(arr[i]);
            j++;
        }
    }
    
    return ans;
}

