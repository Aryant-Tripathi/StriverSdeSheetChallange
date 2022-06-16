#include<bits/stdc++.h>
unordered_set<string> dictionary;
vector<string> ans;

void solve(int index, string temp, string &s)
{
    if(index >= s.size())
    {
        temp.pop_back();
        ans.push_back(temp);
        temp.push_back(' ');
        return;
    }
    
    for(int i = index; i < s.size(); i++)
    {
        string between = s.substr(index, i - index + 1);
        
        if(dictionary.count(between))
        {
            string original = temp;
            temp += between;
            temp.push_back(' ');
            solve(i + 1, temp, s);
            
            temp = original; // backtrack
            
        }
    }
    
}
vector<string> wordBreak(string &s, vector<string> &words)
{
    // Write your code here
    dictionary.clear();
    ans.clear();
    
    for(string word: words)
    {
        dictionary.insert(word);
    }
    
    string temp = "";
    solve(0, temp, s);
    
    return ans;

}