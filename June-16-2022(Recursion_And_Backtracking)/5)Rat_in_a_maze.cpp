vector<vector<int>> ans;

void solve(int i, int j, vector<vector<int>>& temp, 
          vector<vector<int>>&arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size()
      || arr[i][j] == 0 || temp[i][j] == 1)
    {
        return;
    }
    
    if(i == arr.size() - 1 && j == arr.size() - 1 && arr[i][j] == 1)
    {
        vector<int> ForPush;
        temp[i][j] = 1;
        
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < temp.size(); j++)
            {
                ForPush.push_back(temp[i][j]);
            }
        }
        
        if(!ForPush.empty())
            ans.push_back(ForPush);
        
        //return;
    }
    
    temp[i][j] = 1;
    solve(i, j + 1, temp, arr);
    solve(i, j - 1, temp, arr);
    solve(i - 1, j, temp, arr);
    solve(i + 1, j, temp, arr);
    temp[i][j] = 0;
        
}
vector<vector<int> > ratInAMaze(vector<vector<int>>&arr, int n){
  // Write your code here.
    vector<vector<int>> temp;
    for(int i = 0; i < n; i++)
    {
        vector<int> ant;
        for(int j = 0; j < n; j++)
        {
            ant.push_back(0);
        }
        temp.push_back(ant);
    }
    
    solve(0, 0, temp, arr);
    
    return ans;
    
}