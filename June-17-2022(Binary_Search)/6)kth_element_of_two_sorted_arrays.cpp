int LessThan(vector<int>& arr1, vector<int>& arr2, int mid, int k)
{
    int from1 = upper_bound(arr1.begin(), arr1.end(), mid) 
        - arr1.begin();
    
    int from2 = upper_bound(arr2.begin(), arr2.end(), mid) 
        - arr2.begin();
    
    int count = (from1 + from2);
    
    return (count < k);
}
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
    // Write your code here.
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    if(n2 < n1)
        return ninjaAndLadoos(arr2, arr1, n, m, k);
    
    int low = min(arr1[0], arr2[0]);
    int high = max(arr1[n1 - 1], arr2[n2 - 1]);
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(LessThan(arr1, arr2, mid, k))
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