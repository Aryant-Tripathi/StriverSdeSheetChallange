#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &arr)
{
	// Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    bool inrow = false, incol = false;
    
    for(int j = 0; j < col; j++)
    {
        if(arr[0][j] == 0) inrow = true;
    }
    
    for(int i = 0; i < row; i++)
    {
        if(arr[i][0] == 0) incol = true;
    }
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(arr[i][j] == 0)
            {
                
                arr[0][j] = 0;
                arr[i][0] = 0;
                
            }
        }
    }
    
    for(int j = 0; j < col; j++)
    {
        if(arr[0][j] == 0 && j != 0)
        {
            //cout << "here " << 0 << " " << j << endl;
            for(int i = 1; i < row; i++)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        if(arr[i][0] == 0 && i != 0)
        {
            for(int j = 1; j < col; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    if(inrow)
    {
        for(int j = 0; j < col; j++)
        {
            arr[0][j] = 0;
        }
    }
    
    if(incol)
    {
        for(int i = 0; i < row; i++)
        {
            arr[i][0] = 0;
        }
    }
}