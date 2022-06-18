#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &arr1, vector<int> &arr2, int n, int k){
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sum = arr1[i] + arr2[j];
            //pq.push(sum);
            
            if(pq.size() < k) pq.push(sum);
            else 
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
                
            }
        }
    }
    
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    
//     sort(ans.begin(), ans.end(), greater<int>());
    reverse(ans.begin(), ans.end());
    return ans;
}