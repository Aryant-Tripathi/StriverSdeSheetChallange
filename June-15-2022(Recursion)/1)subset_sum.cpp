vector<int> ans;
void solve(int i, int sum, vector<int>& arr)
{
    if(i >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    solve(i + 1, sum, arr);
    solve(i + 1, sum + arr[i], arr);
    
}
vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    ans.clear();
    solve(0, 0, arr);
    
    sort(ans.begin(), ans.end());
    return ans;
}