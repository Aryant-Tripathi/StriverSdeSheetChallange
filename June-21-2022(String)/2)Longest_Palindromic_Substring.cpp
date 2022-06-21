#include<bits/stdc++.h>
int expand(string& s, int left, int right)
{
    while(left>=0 and right<s.length() and s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalinSubstring(string str)
{
    // Write your code here.
    int start = 0, end = 0;
    int maxLen = 0;
    for(int i=0;i<str.length();i++){
        int odd = expand(str, i, i);
        int even = expand(str, i, i+1);
        
        int len = max(odd, even);
        if(maxLen<len){
            maxLen = len;
            start = i - (len-1)/2;
            end = i + (len)/2;
        }
    }
    return str.substr(start, maxLen);
    
    // Don't know why, but this is giving TLE
    /*
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    
    int start = 0, end = 0, len = 0;
    
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {
            if(gap == 0) // single character
            {
                dp[i][j] = true; 
            }
            else if(gap == 1) // two characters
            {
                if(s[i] == s[j]) // e.g aa
                {
                    dp[i][j] = true;
                }
                else     // e.g ab
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if(s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            
            if(dp[i][j] == true && len < gap + 1)
            {
                start = i;
                end = j;
                len = gap + 1;
            }
        }
    }
    
    string ans = s.substr(start, len);
    return ans;
    */
}