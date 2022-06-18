#include<bits/stdc++.h>
priority_queue<int> maxh; // left half
priority_queue<int, vector<int>, greater<int>> minh; // right 

void addNum(int num) 
{
        int left = maxh.size();
        int right = minh.size();
        
        if(left == 0) // yeh phla element hoga push krne ke liye
            maxh.push(num);
        else if(left == right) //Push one element in maxheap for sure
        {
            if(num < minh.top())  //num can be pushed to maxheap (1st half) to maintain order
            maxh.push(num);
            else //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minh.top(); // save root of minheap
                minh.pop(); //Pop the root from minheap
                minh.push(num); //Push num in minheap
                maxh.push(temp); //Push the previous saved root of minheap in the maxheap
                    
            }
        }
        else ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if(minh.size() == 0)
            {
                if(num > maxh.top()) //Push num to 2nd half
                    minh.push(num);
                else //Push num to 1st half
                {
                    int temp = maxh.top();
                    maxh.pop();
                    maxh.push(num);
                    minh.push(temp);
                }
            }
            else if(num >= minh.top()) //Push the element directly in minheap (2nd half)
            {
                minh.push(num);
            }
            else //Push root of maxheap to minheap
            {
                if(num < maxh.top())
                {
                    int temp = maxh.top(); //Save root of maxheap
                    maxh.pop();  //Pop root of maxheap
                    maxh.push(num);  //Push num to maxheap
                    minh.push(temp); //Push previous saved root of maxheap to minheap
                }
                else //Push num to 2nd half
                    minh.push(num);
            }
        } 
}

int findMedian()
{
        int left = maxh.size();
        int right = minh.size();
        if(left > right) //Return top of maxheap for odd no of elements
            return (maxh.top());
        else   //Else return avg of top of maxheap and minheap
            return ((maxh.top()) + (minh.top())) / 2;
            
}

void findMedian(int *arr, int n)
{
    // Write your code here
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        addNum(arr[i]);
        cout << findMedian() << " ";
    }
    cout << endl;
    
}