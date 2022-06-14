#include <bits/stdc++.h>
bool comp(pair<int, int>& a, pair<int, int>& b)
{
    double first = (double)(a.second) / (double)(a.first);
    double second = (double)(b.second) / (double)(b.first);
    
    return first > second;
}
double maximumValue (vector<pair<int, int>>& arr, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    // my idea, kya kr skte hain hm
    // 1) main sort krunga on the basis of ratio
    // 2) ki konse km weight pe mujhe jyada value mil rhi hai
    
    sort(arr.begin(), arr.end(), comp);
    
    double ans = 0;
    int weightadded = 0;
    for(int i = 0; i < n; i++)
    {
        if(weightadded + arr[i].first <= w)
        {
            weightadded += arr[i].first;
            ans += arr[i].second;
        }
        else
        {
            int remain = w - weightadded;
            ans += 
                ((double)arr[i].second / (double)arr[i].first)
                * (double)remain;
            
            break;
        }
    }
    
    return ans;
}