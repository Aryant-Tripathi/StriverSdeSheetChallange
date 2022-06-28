#include<bits/stdc++.h>

priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;

void addNum(int num)
{
    int left = maxh.size();
    int right = minh.size();
    
    if(left == 0)
    {
        maxh.push(num);
    }
    else if(left == right)
    {
        if(num < minh.top())
        {
            maxh.push(num);
        }
        else
        {
            int temp = minh.top();
            minh.pop();
            minh.push(num);
            maxh.push(temp);
        }
    }
    else
    {
        if(minh.size() == 0)
        {
            if(num > maxh.top())
            {
                minh.push(num);
            }
            else
            {
                int temp = maxh.top();
                maxh.pop();
                maxh.push(num);
                minh.push(temp);
            }
        }
        else if(num >= minh.top())
        {
            minh.push(num);
        }
        else
        {
            if(num < maxh.top())
            {
                int temp = maxh.top();
                maxh.pop();
                maxh.push(num);
                minh.push(temp);
            }
            else
            {
                minh.push(num);
            }
        }
    }
}

int GetAnswer()
{
    int left = maxh.size();
    int right = minh.size();
    
    if(left == right + 1)
    {
        return (maxh.top());
    }
    else
    {
        return ((maxh.top() + minh.top()) / 2);
    }
}


vector<int> findMedian(vector<int> &arr, int nn){
    
    // Write your code here 
    int n = arr.size();
    vector<int> ans;
    
    while(!maxh.empty()) maxh.pop();
    while(!minh.empty()) minh.pop();
    
    for(int i = 0; i < n; i++)
    {
        addNum(arr[i]);
        ans.push_back(GetAnswer());
    }
    
    return ans;
}

