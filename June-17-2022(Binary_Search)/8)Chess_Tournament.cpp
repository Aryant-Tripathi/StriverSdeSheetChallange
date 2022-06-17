#include <bits/stdc++.h>
bool Enoughspace(vector<int>& arr, int c, int mid)
{
    int count = 1;
    int prev = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] - arr[prev] >= mid)
        {
            count++;
            prev = i;
        }
    }
    
    return count >= c;
}

int chessTournament(vector<int> arr , int n ,  int c){
    // Write your code here
    sort(arr.begin(), arr.end());
    
    int low = 1;
    int high = arr[n - 1] - arr[0];
        
    int ans = 0;
        
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(Enoughspace(arr, c, mid) == true)
        {
                ans = mid;
                low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return ans;
}