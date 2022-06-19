#include<bits/stdc++.h>
class Stack {
    // Define the data members.

   public:
    queue<int> q1, q2;
    Stack() {
        // Implement the Constructor.
//         q1.clear();
//         q2.clear();
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()) return -1;
        if(q1.size() == 1)
        {
            int top = q1.front();
            q1.pop();
            return top;
        }
        
       while(q1.size() > 1)
       {
           q2.push(q1.front());
           q1.pop();
       }
        
        int top = q1.front();
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        
        return top;
       
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()) return -1;
        if(q1.size() == 1)
        {
            int top = q1.front();
            //q1.pop();
            return top;
        }
        
       while(q1.size() > 1)
       {
           q2.push(q1.front());
           q1.pop();
       }
        
        int top = q1.front();
        q2.push(q1.front());
        
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        
        return top;
    }
};