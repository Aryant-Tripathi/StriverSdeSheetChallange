#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(s.empty())
        {
            ans.push_back(-1);
        }
        else if(arr[i] > s.top())
        {
            ans.push_back(s.top());
        }
        else
        {
            while(!s.empty() && arr[i] <= s.top())
            {
                s.pop();
            }
            
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        
        s.push(arr[i]);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}