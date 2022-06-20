#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    // Write your code here.
    
    public:
        
    stack<int> s1;
    stack<int> s2; // minimum upto till now
    
        // Constructor
        minStack() 
        { 
            // Write your code here.
        }
        
        // Function to add another element equal to num at the top of stack.
        void push(int val)
        {
            // Write your code here.
            s1.push(val);
            
            if(s2.empty() || val <= s2.top())
            s2.push(val);
        }
        
        // Function to remove the top element of the stack.
        int pop()
        {
            // Write your code here.
            if(s1.empty()) return -1;
            int ans = s1.top();
            if(s1.top() == s2.top())
            s2.pop();
            
            s1.pop();
            
            return ans;
        }
        
        // Function to return the top element of stack if it is present. Otherwise return -1.
        int top()
        {
            // Write your code here.
            if(s1.empty()) return -1;
            return s1.top();
        }
        
        // Function to return minimum element of stack if it is present. Otherwise return -1.
        int getMin()
        {
            // Write your code here.
            if(s2.empty()) return -1;
            return s2.top();
        }
};