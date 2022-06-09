#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector<vector<int>> &arr, int row, int col, int target) {
    // Write your code here.
    
    int low = 0;
    int high = (row * col) - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int r = mid / col;
        int c = mid % col;
        
        if(arr[r][c] == target)
        {
            return true;
        }
        else if(arr[r][c] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return false;
    
}