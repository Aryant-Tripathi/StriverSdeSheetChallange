#include <bits/stdc++.h> 

 int merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high)
    {
        int count = 0;
        int tofind = mid + 1;
        
        for(int i = low; i <= mid; i++)
        {
            while(tofind <= high && arr[i] > 2 * (long)arr[tofind])
                tofind++;
            
            count += tofind - (mid + 1);
        }
        
        
        int i = low, j = mid + 1, k = low;
        
        while((i <= mid) && (j <= high))
        {
            if(arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            else 
            {
                // if(arr[i] > 2 * arr[j])
                //     count++;
                
                temp[k] = arr[j];
                k++;
                j++;
            }
        }
        
        while(i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        
        while(j <= high)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        
        for(int l = low; l <= high; l++)
        {
            arr[l] = temp[l];
        }
        
        return count;
    }
    
    int merge_sort(vector<int>& arr, vector<int>& temp, int low, int high)
    {
        if(low >= high) return 0;
        
        int count = 0;
        
        if(low < high)
        {
            int mid = low + (high - low) / 2;
            
            count += merge_sort(arr, temp, low, mid);
            count += merge_sort(arr, temp, mid + 1, high);
            
            count += merge(arr, temp, low, mid, high);
        }
        
        return count;
    }
int reversePairs(vector<int> &arr, int n){
    // Write your code here
    
    vector<int> temp(n);
        
  return merge_sort(arr, temp, 0, n - 1);
    
}