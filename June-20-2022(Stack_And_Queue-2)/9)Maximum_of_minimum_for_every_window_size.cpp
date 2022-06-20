#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    stack<pair<int, int>> s;
    vector<int> left(n,-1);
    
    s.push({arr[0],0});
    
    for(int i = 1; i < n; i++)
    {
        while(s.empty() == false && s.top().first >= arr[i])
            s.pop();
        
        if(s.empty() == false)
            left[i] = s.top().second;
            
            s.push({arr[i],i});
    }
    
    while(s.empty() == false)
        s.pop();
    
    vector<int> right(n,n);
    s.push({arr[n-1],n-1});
    
    for(int i = n - 2; i >= 0; i--)
    {
        while(s.empty() == false && s.top().first >= arr[i])
            s.pop();
        
        if(s.empty() == false)
            right[i] = s.top().second;
        
        s.push({arr[i],i});
    }
        
        vector<int> ans(n ,INT_MIN);
//         for(int i = 0; i <= n; i++)
//         ans[i] = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int len = (right[i] - left[i] - 1) - 1;
         //   cout <<"len" << len << endl;
            if(arr[i]>ans[len])
            ans[len]=arr[i];
           // cout << "ans[len]" << ans[len] << endl;
            
        }
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
        }
        
        return ans;
}