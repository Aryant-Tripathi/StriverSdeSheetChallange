#include<bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
      vector<vector<int>> ans;
   for(int i = 0; i < arr.size()-1; i++){
       vector<int> pair;
       for(int j = i+1; j < arr.size(); j++){          
           if((arr[i] + arr[j]) == s){
               pair.push_back(min(arr[i],arr[j]));
               pair.push_back(max(arr[i],arr[j]));
               ans.push_back(pair);
           }
       }
   }
   sort(ans.begin(),ans.end());
   return ans;
}