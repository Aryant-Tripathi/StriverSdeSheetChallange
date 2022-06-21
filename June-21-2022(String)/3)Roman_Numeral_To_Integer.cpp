#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
     int n = s.length();
        unordered_map<char, int> mp = {{'I', 1},
                                       {'V', 5},
                                       {'X', 10},
                                       {'L', 50},
                                       {'C', 100},
                                       {'D', 500},
                                       {'M', 1000}
                                      };
    
    int ans = mp[s[n - 1]];
    for(int i = n - 2; i >= 0; i--)
    {
        if(mp[s[i]] < mp[s[i + 1]]) // IX
        {
            ans = ans - mp[s[i]];
        }
        else
        {
            ans = ans + mp[s[i]]; // XI
        }
    }
    
    return ans;
}

