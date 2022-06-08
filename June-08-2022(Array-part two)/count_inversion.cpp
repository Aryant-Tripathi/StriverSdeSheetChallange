#include <bits/stdc++.h> 

// https://www.youtube.com/watch?v=kQ1mJlwW-c0

long long merge(long long *arr, long long temp[], 
               int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    long long inv_count = 0;
    
    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
            
            inv_count += (mid - i);
        }
    }
    
    while(i <= mid - 1)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    
    while(j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    for(int l = left; l <= right; l++)
    {
        arr[l] = temp[l];
    }
    
    return inv_count;
}

long long merge_sort(long long *arr, long long temp[], 
                     int left, int right)
{
    long long inv_count = 0;
    if(left < right)
    {
        long long mid = left + (right - left) / 2;
        
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
        
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    
    return inv_count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n] = {0};
    
    return merge_sort(arr, temp, 0, n - 1);
}