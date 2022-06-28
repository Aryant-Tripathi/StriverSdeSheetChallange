void solve(int i, int j, int& newColor, int old, vector<vector<int>> &arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size()
      || arr[i][j] != old)
        return;
    
    arr[i][j] = newColor;
    
    solve(i + 1, j, newColor, old, arr);
    solve(i - 1, j, newColor, old, arr);
    solve(i, j + 1, newColor, old, arr);
    solve(i, j - 1, newColor, old, arr);
    
}
vector<vector<int>> floodFill(vector<vector<int>> &arr, int x, int y, int newColor)
{
    // Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    int old = arr[x][y];
    if(old == newColor) return arr;
    
    solve(x, y, newColor, old, arr);
    return arr;
    
}