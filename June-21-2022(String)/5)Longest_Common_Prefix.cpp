string longestCommonPrefix(vector<string>&arr, int n)
{
    // Write your code here
    if(n == 1) return arr[0];
    
    string pre = "";
    
    for(int i = 0; i < min(arr[0].length(), arr[1].length()); i++)
    {
        if(arr[0][i] == arr[1][i])
        {
            pre += arr[0][i];
        }
        else
            break;
    }
    
    for(int i = 2; i < n; i++)
    {
        string temp = "";
        for(int j = 0; j < min(pre.length(), arr[i].length()); j++)
        {
            if(pre[j] == arr[i][j])
            {
                temp += pre[j];
            }
            else
                break;
        }
        pre = temp;
    }
    
    return pre;
}




