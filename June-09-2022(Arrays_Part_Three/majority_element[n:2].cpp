#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // Write your code here.
    
    int hero = arr[0];
    int power = 1;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == hero) power++;
        else
        {
            power--;
            
            if(power == 0)
            {
                hero = arr[i];
                power = 1;
            }
        }
    }
    
    power = 0;
    for(int i = 0; i < n; i++) if(arr[i] == hero) power++;
    
    if(power > (floor(n / 2)))
        return hero;
    
    return -1;
}