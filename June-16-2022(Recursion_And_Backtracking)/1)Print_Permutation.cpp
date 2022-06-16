#include<bits/stdc++.h>

vector<string> ans;

void solve(int index, string& s)
{
    if(index >= s.size())
    {
        ans.push_back(s);
        return;
    }
    
    for(int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        solve(index + 1, s);
        swap(s[index], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    ans.clear();
    int n = s.size();
    
    solve(0, s);
    return ans;
}