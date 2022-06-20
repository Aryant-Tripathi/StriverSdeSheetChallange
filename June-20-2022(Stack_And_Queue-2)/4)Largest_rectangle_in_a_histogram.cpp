#include<bits/stdc++.h>
int largestRectangle(vector<int>&arr) {
   // Write your code here.
     int n = arr.size();
     vector<int> left;
     stack<pair<int, int>> s;
     int pseudoindex = -1;
     
     // NSL
     for(int i = 0; i < n; i++)
     {
         if(s.empty())
         {
             left.push_back(pseudoindex);
         }
         else if(s.top().first < arr[i])
         {
             left.push_back(s.top().second);
         }
         else
         {
             while(!s.empty() && s.top().first >= arr[i])
             {
                 s.pop();
             }
             
             if(s.empty())
             {
                 left.push_back(pseudoindex);
             }
             else
             {
                 left.push_back(s.top().second);
             }
         }
         s.push({arr[i], i});
     }
     
     while(!s.empty()) s.pop();
     
     vector<int> right;
     pseudoindex = n;
     
     // NSR
     for(int i = n - 1; i >= 0; i--)
     {
         if(s.empty())
         {
             right.push_back(pseudoindex);
         }
         else if(s.top().first < arr[i])
         {
             right.push_back(s.top().second);
         }
         else
         {
             while(!s.empty() && s.top().first >= arr[i])
             {
                 s.pop();
             }
             
             if(s.empty())
             {
                 right.push_back(pseudoindex);
             }
             else
             {
                 right.push_back(s.top().second);
             }
         }
         s.push({arr[i], i});
     }
     
     reverse(right.begin(), right.end());
     
     vector<int> area(n);
     for(int i = 0; i < n; i++)
     {
         area[i] = arr[i] * (right[i] - left[i] - 1);
     }
     
     int mx = *max_element(area.begin(), area.end());
     return mx;
     
 }