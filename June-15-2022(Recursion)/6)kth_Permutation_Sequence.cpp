#include<bits/stdc++.h>
/* IDEA: 
    1) First store factorial
    2) index = k / (n - 1)!
    3) if(k % fact[n - 1] == 0) index--; // for boudry cases blocks
    4) ans += char(digits[index]);
    5) Erase used digit from digits array, as they should be unique
    6) New k, k = k - fact[n - 1] * index;
    
    Base, if n == 1, return the left digit
    
    if(n == 4)
    digits [] = [1, 2, 3, 4]
    
    Block size = (n - 1)!
    
    After putting a value, we have to skip some permuatations,
    and that is equal to (number of blocks) * (elements in each box)
    this is basically (index) * (fact[n - 1])
    
 */
    vector<int> fact;
    vector<int> digits;

void solve(int n, int k, string& ans)
    {
        if(n == 1)
        {
            // push the leftover digit of digits array
            ans += to_string(digits[0]);
            return;
        }
        
        int index = k / (fact[n - 1]);
        
        if(k % fact[n - 1] == 0) // for boundry cases blocks
        {
            index--; // need to comvert 1 based indexing to zero case, so index--
        }
        
        ans += to_string(digits[index]); //Add new character
        digits.erase(digits.begin() + index);  //Erase digit after using
        
        k -= (index * fact[n - 1]);
        
        solve(n - 1, k, ans);
        
    }
string kthPermutation(int n, int k) {
    // Write your code here.
    
    digits.clear();
    fact.clear();
    // 1) store all factorial (here we have array name as fact)
        fact.push_back(1);
        int val = 1; // to calculate more factorial
        
        for(int i = 1; i < n; i++)
        {
            val *= i;
            fact.push_back(val);
        }
        
        // 2) making digits array
        for(int i = 1; i <= n; i++)
            digits.push_back(i);
        
        string ans = "";
        solve(n, k, ans);
        
        return ans;
}

