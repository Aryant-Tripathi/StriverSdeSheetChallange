#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    stringstream ss(str);
    string word;
    
    vector<string> words;
    while(ss >> word)
    {
        words.push_back(word);
    }
    
    string ans = "";
    for(int i = words.size() - 1; i >= 0; i--)
    {
        ans += words[i];
        ans.push_back(' ');
    }
    
    return ans;
}