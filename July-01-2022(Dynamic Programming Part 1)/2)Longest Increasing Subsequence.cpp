 /*
 We need to find maximum increasing subsequence length. In the brute-force approach, we can model this problem as -
1) If the current element is greater than the previous element, then we can either pick it or dont pick it because we may get a smaller element somewhere ahead which is greater than previous and picking that would be optimal. So we try both options.
2)If the current element is smaller or equal to previous element, it can't be picked. 

(since N is 10^5 so recursive dp will not work)
so we have to use binary search in this
T.C --> O(nlogn)
*/

#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> store;
    for(int i = 0; i < n; i++)
    {
        if(store.empty() || store[store.size() - 1] < arr[i])
        {
            store.push_back(arr[i]);
        }
        else
        {
            // Find the index of the smallest number >= arr[i]
            auto it = 
                lower_bound(store.begin(), store.end(), arr[i]);
            
            *it = arr[i]; // Replace that number with arr[i]
        }
    }
    
    return (int)store.size();
}

