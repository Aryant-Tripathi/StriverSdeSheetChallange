#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int left = target - (arr[i] + arr[j]);
            
            if(mp.find(left) != mp.end())
            {
                pair<int, int> it = mp[left];
                    int k = it.first;
                    int l = it.second;
                    
                    if(i != k && i != l && j != k && j != l)
                        return "Yes";
            }
        }
    }
    
    return "No";
    
//    sort(arr.begin(), arr.end());
    
//     for(int i = 0; i < n - 3; i++)
//     {
//         for(int j = i + 1; j < n - 2; j++)
//         {
//             int low = j + 1, high = n - 1;
//             while(low < high)
//             {
//                 int sum = arr[i] + arr[j];
//                 if(sum + arr[low] + arr[high] == target)
//                 {
//                     return "Yes";
//                 }
//                 else if(sum + arr[low] + arr[high] < target)
//                 {
//                     low++;
//                 }
//                 else
//                 {
//                     high--;
//                 }
//             }
//         }
//     }
    
//     return "No";
    
    
 }

