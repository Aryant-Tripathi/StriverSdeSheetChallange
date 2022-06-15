#include<bits/stdc++.h>
vector<vector<string>> ans;
bool is_palindrome(string &s, int low, int high)
{
    while(low <= high)
    {
        if(s[low] != s[high])
            return false;
        
        low++;
        high--;
    }
    
    return true;
}
void solve(int i, vector<string>& temp, string& s)
{
    if(i >= s.size())
    {
        ans.push_back(temp);
        return;
    }
    
    for(int k = i; k < s.size(); k++)
    {
        if(is_palindrome(s, i, k))
        {
            temp.push_back(s.substr(i, k - i + 1));
            solve(k + 1, temp, s);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> temp;
    solve(0, temp, s);
    return ans;
}