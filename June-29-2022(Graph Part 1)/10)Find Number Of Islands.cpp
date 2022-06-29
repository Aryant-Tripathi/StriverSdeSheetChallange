void dfs(int i, int j, int row, int col, int** arr)
{
    if(i < 0 || j < 0 || i >= row || j >= col || arr[i][j] == 0)
        return;
    
    arr[i][j] = 0;
    
    dfs(i, j + 1, row, col, arr);
    dfs(i, j - 1, row, col, arr);
    dfs(i - 1, j, row, col, arr);
    dfs(i + 1, j, row, col, arr);
    dfs(i - 1, j - 1, row, col, arr);
    dfs(i + 1, j - 1, row, col, arr);
    dfs(i - 1, j + 1, row, col, arr);
    dfs(i + 1, j + 1, row, col, arr);
    
}
int getTotalIslands(int** arr, int row, int col)
{
   // Write your code here.
    int count = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == 1)
            {
                count++;
                dfs(i, j, row, col, arr);
            }
        }
    }
    
    return count;
}

