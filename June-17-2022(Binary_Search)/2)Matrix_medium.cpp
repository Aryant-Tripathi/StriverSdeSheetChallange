int LessThanOrEqualToMidInRow(vector<int>& row, int number)
{
    int low = 0;
    int high = row.size() - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(row[mid] <= number)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}
int getMedian(vector<vector<int>> &arr)
{
    // Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    int low = 0;
    int high = 100001;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            count += LessThanOrEqualToMidInRow(arr[i], mid);
        }
        
        if(count <= (row * col) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}