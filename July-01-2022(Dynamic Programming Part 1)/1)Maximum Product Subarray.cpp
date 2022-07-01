int maximumProduct(vector<int> &arr, int nm)
{
	// Write your code here
    int n = arr.size();
    
    if(n == 1) return arr[0];
    
    int mx = 1, mn = 1;
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0) swap(mx, mn);
        
        mx = max(arr[i], mx * arr[i]);
        mn = min(arr[i], mn * arr[i]);
        
        ans = max(ans, mx);
        
    }
    
    return ans;
}

