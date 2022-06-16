//#define<bits/stdc++.h>
bool isPossible(int node, int color[], int n,
                vector<vector<int>>& arr, int thiscolor)
{
    for(int i = 0; i < n; i++)
    {
        if(i != node && arr[i][node] == 1 && color[i] == thiscolor)
        {
            return false;
        }
    }
    
    return true;
}
bool solve(int node, int color[], int n, int m, 
           vector<vector<int>>& arr)
{
    if(node == n)
    {
        return true;
    }
    
    for(int i = 1; i <= m; i++)
    {
        if(isPossible(node, color, n, arr, i))
        {
            color[node] = i;
            if(solve(node + 1, color, n, m, arr))
            {
                return true;
            }
            
            color[node] = 0;
        }
    }
    
    return false;
}
string graphColoring(vector<vector<int>> &arr, int m) {
    // Write your code here
    int n = arr.size();
    int color[n] = {0};
    
    if(solve(0, color, n, m, arr))
    {
        return "YES";
    }
    
    return "NO";
}