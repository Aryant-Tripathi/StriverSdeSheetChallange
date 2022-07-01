#include<bits/stdc++.h>

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    // Write your code here
    int t[n];
        t[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            t[i] = arr[i];
            for(int j = 0; j < i; j++)
            {
                if(arr[i] > arr[j])
                {
                    t[i] = max(t[i],t[j]+arr[i]);
                }
            }
        }
        return *max_element(t,t+n);
}