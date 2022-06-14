int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    
    int ans = 1;
    int curr_platform = 1;
    
    int i = 1, j = 0;
    while(i < n && j < n)
    {
        if(at[i] <= dt[j])
        {
            curr_platform++;
            i++;
        }
        else
        {
            curr_platform--;
            j++;
        }
        
        ans = max(ans, curr_platform);
    }
    
    return ans;
}