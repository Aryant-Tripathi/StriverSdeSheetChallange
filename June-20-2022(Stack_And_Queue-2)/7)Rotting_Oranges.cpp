#include<bits/stdc++.h>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

bool IsValid(int i, int j, vector<vector<int>>& arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
        return false;
    
    if(arr[i][j] != 1)
        return false;
    
    return true;
}
int minTimeToRot(vector<vector<int>>& arr, int n, int m)
{
    // Write your code here. 
    int row = arr.size();
    int col = arr[0].size();
    
    int fresh = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == 1)
            {
                fresh++;
            }
            else if(arr[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    
    int steps = -1;
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++)
            {
                int new_x = curr_x + dx[k];
                int new_y = curr_y + dy[k];
                
                if(IsValid(new_x, new_y ,arr) == false)
                    continue;
                
                fresh -= 1;
                arr[new_x][new_y] = 2;
                q.push({new_x, new_y});
            }
        }
        steps++;
    }
    
    if(fresh > 0)
        return -1;
    
    if(steps == -1)
        return 0;
    
    return steps;
}