#include<bits/stdc++.h>
void putValue(int val, stack<int>& s)
{
    if(s.empty() || val > s.top())
    {
        s.push(val);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    putValue(val, s);
    s.push(temp);
    
}
void sortStack(stack<int> &s)
{
    // Write your code here
    if(s.size() == 1)
    {
        return;
    }
    
    int val = s.top();
    s.pop();
    sortStack(s);
    putValue(val, s);
    
}