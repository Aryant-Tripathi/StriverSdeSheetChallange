bool check(int arr[9][9], int row, int col, int k)
{
    for(int i = 0; i < 9; i++)
    {
        if(arr[i][col] == k)
            return false;
        
        if(arr[row][i] == k)
            return false;
        
        // for 3 * 3 block
        int first = 3 * (row / 3) + (i % 3);
        int second = 3 * (col / 3) + (i % 3);
        
        if(arr[first][second] == k)
            return false;
    }
    
    return true;
}
bool solve(int arr[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arr[i][j] == 0) // if it is zero
            {
                // we try to put every value here from 1 to 9
                for(int k = 1; k <= 9; k++)
                {
                    if(check(arr, i, j, k))
                    {
                        arr[i][j] = k;
                        bool move = solve(arr);
                        if(move == true)
                        {
                            return true;
                        }
                        else
                        {
                            arr[i][j] = 0;
                        }
                    }
                }
                //maine sb lga ke dekh liya, khin true nhi mila
                // toh false return kro
                return false;
            }
        }
    }
    
    return true;
}
bool isItSudoku(int arr[9][9]) {
    // Write your code here.
    
    return solve(arr);
}

