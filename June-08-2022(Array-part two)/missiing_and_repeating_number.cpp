#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here 
    
    for(int i = 0; i < n; i++)
    {
        arr[abs(arr[i]) - 1] = -1 *  arr[abs(arr[i]) - 1];
    }
    
    int one, two;
    bool firstdone = false;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0 && firstdone == false) 
        {
            one = i + 1; 
            firstdone = true;
        }
        else if(arr[i] > 0)
        {
            two = i + 1;
        }
    }
    
    int otimes = 0, ttimes = 0;
    for(int i = 0; i < n; i++)
    {
        if(abs(arr[i]) == one)
            otimes++;
        else if(abs(arr[i]) == two)
            ttimes++;
    }
    
    //cout << otimes << " " <<
    if(otimes == 2)
        return {two, one};
    
    return {one, two};
 }

