#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    for(int i = 0; i < n; i++)
    {
        maxh.push(arr[i]);
        minh.push(arr[i]);
        
        if(maxh.size() > k) maxh.pop();
        if(minh.size() > k) minh.pop();
    }
    
    return {maxh.top(), minh.top()};
}