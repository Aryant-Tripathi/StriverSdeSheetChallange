#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &arr) {
    // Write your code here.
    int n = arr.size();
    
    // NGL
    stack<pair<int, int>> s; // value, index
    vector<int> left;
    
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
        {
            left.push_back(-1);
        }
        else if(s.top().first > arr[i])
        {
            left.push_back(s.top().second);
        }
        else
        {
            while(!s.empty() && s.top().first <= arr[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    
    for(int i = 0; i < n; i++)
    {
        left[i] = i - left[i];
    }
    
    return left;
}