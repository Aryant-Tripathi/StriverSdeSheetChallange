#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n)
{
    //  Write your code here.
    int mn = -1;
    for(int i = n - 1; i > 0; i--)
    {
        if(arr[i] > arr[i - 1])
        {
            mn = i - 1;
            break;
        }
    }
    
    if(mn < 0)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] > arr[mn])
        {
            swap(arr[mn], arr[i]);
            reverse(arr.begin() + mn + 1, arr.end());
            break;
        }
    }
    
    return arr;
}

/* Algorithm:

step 1: Linearly traverse given array from the end and find a number that is greater than its adjacent nums[i] > nums[i-1]. Store the index of smaller number in breakPoint variable. If there is no such element, reverse entire array and return.

step 2: Linearly traverse from the end and this time find a number larger than nums[breakPoint]. Let's call it nums[i].

step 3: Swap nums[i] and nums[breakPoint].

step 4: Reverse the array from index breakPoint + 1 to nums.size().

Example:

Consider nums[] = [1, 3, 5, 4, 2].
Traverse from back and find a breakpoint. Here, index breakPoint = 1 and nums[breakPoint] = 3
Traverse from back and find a number larger than this. Here this number is: nums[i] = 4
Swap nums[breakPoint] and nums[i]. Value after swapping: nums[] = [1, 4, 5, 3, 2].
Reverse array from breakPoint + 1 to nums.size() i.e. these elements: [1, 4, 5, 3, 2]
Final answer = [1, 4, 2, 3, 5]. */