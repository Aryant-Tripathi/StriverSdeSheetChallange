#define ll long long

bool IsPossible(vector<int>& arr, ll mid, int days)
{
    int count = 1;
    ll time = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(time + arr[i] <= mid) time += arr[i];
        else
        {
            count++;
            if(count > days || arr[i] > mid)
                return false;
            
            time = arr[i];
        }
    }
    
    return true;
}
long long ayushGivesNinjatest(int days, int n, vector<int> arr) 
{    
    // Write your code here.
    
    ll sum = 0;
    for(int i = 0; i < arr.size(); i++) sum += (ll)arr[i];
    
    ll low = 0;
    ll high = sum;
    ll ans = -1;
    
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if(IsPossible(arr, days, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return ans;
    
  
}
