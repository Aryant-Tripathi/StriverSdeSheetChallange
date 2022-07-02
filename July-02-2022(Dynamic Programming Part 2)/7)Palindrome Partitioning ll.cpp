#include<bits/stdc++.h>
int t[2001];
    bool CheckPalindrome(int low, int high, string& s)
    {
        while(low < high)
        {
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        
        return true;
    }
    int solve(int i, int high, string& s)
    {
        if(i >= high) return 0;
        
        if(CheckPalindrome(i, high, s)) return 0;
        
        if(t[i] != -1) return t[i];
        
        int ans = INT_MAX;
        
        for(int k = i; k < high; k++)
        {
            //We will recurse for only right part
            // Only when left part turns out to be palindrome
            
            if(CheckPalindrome(i, k, s))
            {
                int temp = solve(k + 1, high, s) + 1;
                ans = min(ans, temp);
            }
        }
        
        return t[i] = ans;
    }
    
int palindromePartitioning(string s) {
    // Write your code here
    int n = s.length();
        
        memset(t, -1, sizeof(t));
        return solve(0, n - 1, s);
}

