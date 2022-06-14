#include<bits/stdc++.h>
struct meeting
{
    int start;
    int end, position;
};

bool comp(struct meeting arr1, struct meeting arr2)
{
    if(arr1.end < arr2.end) 
    {
        return true;
    }
    else if(arr1.end > arr2.end)
    {
        return false;
    }
    else if(arr1.end == arr2.end)
    {
        // ab positon ke basis pe return krenge
        if(arr1.position < arr2.position)
        {
            return true;
        }
    }
    
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    
    struct meeting arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].position = i + 1;
    }
    
    // kyunki hme position ka bhi khayal rkhna hai
    sort(arr, arr + n, comp);
    
    vector<int> ans;
    ans.push_back(arr[0].position); // first meeeting definateily ocurs
    
    int prev = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i].start > arr[prev].end)
        {
            prev = i;
            ans.push_back(arr[i].position);
        }
    }
    
    return ans;
    
}