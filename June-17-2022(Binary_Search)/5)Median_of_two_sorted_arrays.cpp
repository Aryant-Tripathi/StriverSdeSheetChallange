#include<bits/stdc++.h>
double median(vector<int> arr1, vector<int> arr2)
{
    // Write your code here.
     // https://www.youtube.com/watch?v=NTop3VTjmxk&t=157s
    
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    if(arr2.size() < arr1.size())
        return median(arr2, arr1);
    
    int low = 0;
    int high = n1;
    
    while(low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = ((n1 + n2 + 1) / 2) - cut1;
        
        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        
        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];
        
        if(left1 <= right2 && left2 <= right1)
        {
            if((n1 + n2) % 2 == 0)
            {
                return 
                  (max(left1, left2) + min(right1, right2)) /  2.0;
            }
            else
            {
                return double(max(left1, left2));
            }
        }
        else if(left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    
    return 0.0;
}

