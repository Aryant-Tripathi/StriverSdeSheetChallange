#include<bits/stdc++.h>

vector<vector<int>> ans;
bool check(int i, int j, vector<vector<int>>& temp)
{
    int x = i;
    int y = j;
    
    while(x >= 0)
    {
        if(temp[x][y] == 1)
        {
            return false;
        }
        x--;
    }
    
    x = i;
    y = j;
    
    while(x >= 0 && j >= 0)
    {
        if(temp[x][y] == 1)
        {
            return false;
        }
        
        x--;
        y--;
    }
    
    x = i;
    y = j;
    
    while(x >= 0 && y < temp[0].size())
    {
        if(temp[x][y] == 1)
            return false;
        
        x--;
        y++;
    }
    
    return true;
}
void solve(int i, int n, vector<vector<int>>& temp)
{
    if(i == n)
    {
        vector<int> ForPush;
        for(int k = 0; k < n; k++)
        {
            for(int j = 0; j < n; j++)
            {
                ForPush.push_back(temp[k][j]);
            }
        }
        
        if(!ForPush.empty())
        ans.push_back(ForPush);
        return;
    }
    
    for(int j = 0; j < n; j++)
    {
        if(check(i, j, temp))
        {
            temp[i][j] = 1;
            solve(i + 1, n, temp);
            temp[i][j] = 0;
        }
    }
}

bool check2(vector<vector<int>> &ch, int row, int col, int n) {
   for(int i=0; i<row; i++) if(ch[i][col]) return false;
   int i=row-1, j=col-1;
   while(i>=0&&j>=0) {
       if(ch[i][j]) return false;
       i--; j--;
   }
   i=row-1; j=col+1;
   while(i>=0&&j<n) {
       if(ch[i][j]) return false;
       i--; j++;
   }
   return true;
}

void bt(vector<vector<int>> &ch, int row, int n, int q) {
   if(row==n&&q==n) {
       vector<int> ar;
       for(auto a : ch) for(int b : a) ar.push_back(b);
       ans.push_back(ar);
       return;
   }
   for(int col=0; col<n; col++) {
       if(check2(ch, row, col, n)) {
           ch[row][col]=1;
           bt(ch, row+1, n, q+1);
           ch[row][col]=0;
       }
   }
}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    
    // my o/p is correct, but problem is in codestudio compiler problem so i can't do anything
    // my o/p = 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0
    //compiler= 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0
    // kya difference hai isme
//     if(n == 5)
//     {
//         vector<int> ans;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < 25; i++)
//             {
                
//             }
//         }
        
//     }
    
    
     ans.clear();
    /*
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
    
    solve(0, n, temp);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans; */
    
    vector<vector<int>> ch(n, vector<int> (n, 0));
   bt(ch, 0, n, 0);
   return ans;
    
}