#include<bits/stdc++.h>
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    
    int i = 0,  j = 0;
    int orig = k;
    int ans = INT_MIN;
    
    while(j < n && i < n)
    {
        if(arr[j] == 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            if(k > 0)
            {
                ans = max(ans, j - i + 1);
                k--;
                j++;
            }
            else
            {
                if(arr[i] == 0)
                {
                    if(k < orig) k++;
                }
                i++;
            }
        }
    }
    
    return ans;
}

