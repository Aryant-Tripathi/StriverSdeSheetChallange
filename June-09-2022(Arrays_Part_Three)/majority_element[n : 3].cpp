#include <bits/stdc++.h> 

  //given n numbers and the k counters, only less than n/(k+1) times pair-out can happen.

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    
    int hero1 = -1, power1 = 0;
    int hero2 = -1, power2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(hero1 == arr[i])
        {
            power1++;
        }
        else if(hero2 == arr[i])
        {
            power2++;
        }
        else if(power1 == 0)
        {
            hero1 = arr[i];
            power1 = 1;
        }
        else if(power2 == 0)
        {
            hero2 = arr[i];
            power2 = 1;
        }
        else 
        {
            power1--;
            power2--;
        }
    }
    
    power1 = power2 = 0;
    for(int x: arr)
    {
        if(x == hero1) power1++;
        if(x == hero2) power2++;
    }
    
    vector<int> ans;
    
    if(power1 > floor(n / 3)) ans.push_back(hero1);
    if(power2 > floor(n / 3) && hero1 != hero2)
        ans.push_back(hero2);
    
    return ans;

}