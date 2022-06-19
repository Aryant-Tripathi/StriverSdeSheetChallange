#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
    // Write your code here.
    int n = s.size();
    stack<char> st;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty())
            {
                if((s[i] == ')' && st.top() == '(') ||
                   (s[i] == '}' && st.top() == '{') ||
                   (s[i] == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
    
    if(st.size() > 0) return false;
    return true;
}