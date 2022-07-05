vector<vector<int>> ans;
    
    void solve(int i, vector<int>& temp, vector<int>& arr)
    {
        // base condition
        if(i >= arr.size())
        {
            ans.push_back(temp);
            return;
        }
        
        // 1st choice, pick this element
        temp.push_back(arr[i]);
        solve(i + 1, temp, arr);
        
        // 2nd choice, not pick this element
        temp.pop_back(); // backtracking here
        solve(i + 1, temp, arr);
        
    }

vector<vector<int>> pwset(vector<int>arr)
{
    //Write your code here
    int n = arr.size();
        
        vector<int> temp;
        solve(0, temp, arr);
        
        return ans;
}