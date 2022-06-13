int removeDuplicates(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 1;
    int prev = arr[0];
    int temp = 0;
    for(int i = 1; i < n;)
    {
        if(arr[i] == prev)
        {
            while(i < n && prev == arr[i])
            {
                i++;
            }
//             cout << i << endl;
        }
        else
        {
            ans++;
            prev = arr[i];
            i++;
        }
    }
    
    
    return ans;
}