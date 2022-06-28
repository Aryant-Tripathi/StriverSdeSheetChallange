#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        for(int x: arr)
        {
            pq.push(x);
        }
    }

    void add(int num) {
        // Write your code here.
        if(num <= pq.top()) return;
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};